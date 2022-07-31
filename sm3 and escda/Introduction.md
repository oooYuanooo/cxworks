# Introduction

## ecdsa篇

### A.具体项目代码说明

1. 实现欧几里得算法，扩展欧几里得算法，利用扩展欧几里得算法求模逆  exgcd(a,b)  MI(a,m)
2. 定义椭圆曲线，以及在椭圆曲线上实现加法，倍乘，乘法 EC_add(p,q)  EC_double(p) EC_multiply(s,p)
3. 利用secrets库生成私钥，再利用私钥生成公钥，公钥压缩函数，密钥对生成，利用密钥进行签名算法的实现以及验证函数
4. 编写签名伪造算法如下：

```python
def F_signature(public_key,msg):
    u = secrets.randbelow(P)
    v = secrets.randbelow(P)
    Iv = MI(v,N)
    X2 = EC_add(EC_multiply(u,BASE_POINT),EC_multiply(v,public_key))
    forge_rx = X2[0]
    forge_e = forge_rx*u*Iv % N
    forge_s = forge_rx*Iv % N
    forge_sig = (forge_rx,forge_s)
    print("伪造签名为：({},{})".format(hex(forge_sig[0])[2:],hex(forge_sig[1])[2:]))
    print("===============利用伪造签名进行认证===============")
    print()
    if verify(public_key,msg,forge_sig,forge_e):
        print("伪造签名通过验证!!!")
        return True
```

 5.编写主函数实现中本聪签名伪造

### B.运行指导

直接运行 ecdsa.py文件

### C.代码运行全过程截图

![image-20220731084344464](C:\Users\19577\Desktop\image-20220731084344464.png)

## SM3篇

### A.具体项目代码说明

1. 利用gmssl库中提供的SM3加密算法进行项目实现

2. 生日攻击中，函数的定义如下：

   ```python
   def birth_atk(e):
       num = int(2 ** (e / 2))
       ans = [-1] * 2**e
       for i in range(num):
           temp = int(cip_hash[0:int(e / 4)], 16)
           if ans[temp] == -1:
               ans[temp] = i
           else:
               return hex(temp)
   ```

3. rho环路攻击中，函数定义如下：

   ```python
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
   ```

4. 长度扩展攻击中，先将gmssl库中的SM3加密函数进行重写，便于后续对攻击的实现，然后定义攻击的函数如下：

   ```python
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
   ```

### B.运行指导

直接运行 python文件即可

### C.代码运行全过程截图

截图见附件