import random
from gmssl import sm3, func
from timeit import default_timer as timer


ciphertext_m = random.random()
ciphertext = str(ciphertext_m)
cip_len = len(ciphertext)
cip_hash = sm3.sm3_hash(func.bytes_to_list(bytes(ciphertext, encoding='utf-8')))


def birth_atk(e):
    num = int(2 ** (e / 2))
    ans = [-1] * 2**e
    for i in range(num):
        temp = int(cip_hash[0:int(e / 4)], 16)
        if ans[temp] == -1:
            ans[temp] = i
        else:
            return hex(temp)


if __name__ == '__main__':
    example = 24
    tic = timer()
    col = birth_atk(example)
    toc = timer()
    print("找到前24位的碰撞,十六进制表示为:{}。".format(col))
    print("生日攻击所需时间如下：")
    print(toc - tic,'s')  # 输出的时间，秒为单位
