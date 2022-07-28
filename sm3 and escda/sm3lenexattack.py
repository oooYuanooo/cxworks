import random
import struct
from gmssl import sm3, func


ciphertext_m = random.random()
ciphertext = str(ciphertext_m)
cip_len = len(ciphertext)
cip_hash = sm3.sm3_hash(func.bytes_to_list(bytes(ciphertext, encoding='utf-8')))
add_m = "195774688"
pad=[]
pad_str=''


def sm3_hash(msg, v1):
    # print(msg)
    len1 = len(msg)
    reserve1 = len1 % 64
    msg.append(0x80)
    reserve1 = reserve1 + 1
    # 56-64, add 64 byte
    range_end = 56
    if reserve1 > range_end:
        range_end = range_end + 64

    for i in range(reserve1, range_end):
        msg.append(0x00)

    bit_length = (len1) * 8
    bit_length_str = [bit_length % 0x100]
    for i in range(7):
        bit_length = int(bit_length / 0x100)
        bit_length_str.append(bit_length % 0x100)
    for i in range(8):
        msg.append(bit_length_str[7-i])

    group_count = round(len(msg) / 64) - 1

    B = []
    for i in range(0, group_count):
        B.append(msg[(i + 1)*64:(i+2)*64])

    V = []
    V.append(v1)
    for i in range(0, group_count):
        V.append(sm3.sm3_cf(V[i], B[i]))

    y = V[i+1]
    result = ""
    for i in y:
        result = '%s%08x' % (result, i)
    return result

def padding(mes):
    l = len(mes)
    mes.append(0x80)
    l = l+1
    tail = l % 64
    end = 56
    if tail>end:
        end = end + 64
    for i in range(tail,end):
        mes.append(0x00)
    blen = (l-1)*8
    mes.extend([int(x) for x in struct.pack('>q', blen)])
    for j in range(int((l - 1) / 64) * 64 + (l- 1) % 64, len(mes)):
        global pad,pad_str
        pad.append(mes[j])
        pad_str += str(hex(mes[j]))
    return mes


def G_hash(c_hash,c_len,add_m):
    """
    sm3长度扩展攻击
    :param c_hash:密文的哈希值
    :param c_len:密文长度
    :param add_m:附加消息
    :return:密文级联碰撞级联附加消息的哈希值
    """
    vec = []
    mes = ""
    # 对密文的哈希值进行每八位一组的分组
    for i in range(0,len(c_hash),8):
        vec.append(int(c_hash[i:i+8],16))

    if c_len>64:
        for j in range(0,int(c_len/64)*64):
            mes = mes + "a"

    for k in range(0,c_len%64):
        mes = mes + "a"

    mes = func.bytes_to_list(bytes(mes,encoding="utf-8"))
    mes = padding(mes)
    mes.extend(func.bytes_to_list(bytes(add_m,encoding="utf-8")))
    return sm3_hash(mes,vec)

if __name__ == '__main__':
    g_hash = G_hash(cip_hash,cip_len,add_m)
    mes1 = func.bytes_to_list(bytes(ciphertext,encoding="utf-8"))
    mes1.extend(pad)
    mes1.extend(func.bytes_to_list(bytes(add_m,encoding="utf-8")))
    mes1_str = ciphertext+pad_str+add_m
    hash1 = sm3.sm3_hash(mes1)
    print("=========================生成ciphertext====================")
    print("ciphertext: " + ciphertext)
    print("ciphertext length:%d" % len(ciphertext))
    print("ciphertext hash:" + cip_hash)
    print("附加消息:", add_m)
    print("===========================================================")
    print("构造的消息的hash值")
    print("g_hash:" + g_hash)
    print("===========================================================")
    print("==========================验证攻击是否成功====================")
    print("计算hash(ciphertext+padding+add_m')")
    print("new message: \n" + mes1_str)
    print("hash(new message):" + hash1)
    if  hash1== g_hash:
        print("攻击成功！")
    else:
        print("攻击失败！")