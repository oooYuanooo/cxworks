import random
from gmssl import sm3, func
from timeit import default_timer as timer

def rhoattack():
    ciphertext_m = random.random()
    ciphertext = str(ciphertext_m)
    cip_hash1 = sm3.sm3_hash(func.bytes_to_list(bytes(ciphertext, encoding='utf-8')))
    cip_hash2 = sm3.sm3_hash(func.bytes_to_list(bytes(cip_hash1, encoding='utf-8')))
    while True:
        cip_hash1 = sm3.sm3_hash(func.bytes_to_list(bytes(cip_hash1, encoding='utf-8')))
        cip_hash2 = sm3.sm3_hash(func.bytes_to_list(bytes(cip_hash2, encoding='utf-8')))
        cip_hash2 = sm3.sm3_hash(func.bytes_to_list(bytes(cip_hash2, encoding='utf-8')))
        if cip_hash1[0:3]==cip_hash2[0:3]:
            print("找到一组24bit碰撞，出现环如下：")
            print(cip_hash1)
            print(cip_hash2)

            return 0
    return 1

if __name__ == '__main__':
    tic = timer()
    rhoattack()
    toc = timer()
    print("rho attack 所需时间如下：")
    print(toc - tic,'s')  # 输出的时间，秒为单位



