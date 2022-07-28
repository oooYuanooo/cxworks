import secrets
from hashlib import sha256

# 椭圆曲线公式 y^2 = x^3 + Ax + B
A = 0
B = 7

# 对基点进行定义
BASE_X = 55066263022277343669578718895168534326250603453777594175500187360389116729240
BASE_Y = 32670510020758816978083085130507043184471273380659243275938904335757337482424
BASE_POINT = (BASE_X, BASE_Y)
# The proven prime
P = 115792089237316195423570985008687907853269984665640564039457584007908834671663
# The order of the base point on the curve (number of points the base point generates under repeated addition)
N = 115792089237316195423570985008687907852837564279074904382605163141518161494337


# 扩展欧几里得算法实现
def exgcd(a,b):
    if a==b:
        return (a,1,0)
    else:
        i=0
        arra=[a]
        arrb=[b]
        arrq=[]
        arrr=[]

        H=True

        while  H:
            arrq.append(arrb[i]//arra[i])
            arrr.append(arrb[i]%arra[i])
            arrb.append(arra[i])
            arra.append(arrr[i])
            i = i+1
            if arrr[i-1]==0:
                H=False

        i= i-1
        gcd = arra[i]
        arrx=[1]
        arry=[0]

        i=i-1
        counts = i

        while i>=0:
            arry.append(arrx[counts-i])
            arrx.append(arry[counts-i]-arrq[i]*arrx[counts-i])
            i = i-1

        return (gcd,arrx[-1],arry[-1])


# print(exgcd(28, 161))
# print(exgcd(14, 24))

# 利用扩展欧几里得算法求模逆
def MI(a,m):
    (gcd,x,y) =exgcd(a,m)
    if gcd==1:
        return x%m
    else:
        return -1

# print(MI(14, 25))
# print(MI(345, 1234))
# print(MI(3, 37))
# print(MI(20, 5))

def EC_add(p,q):
    if p==0 and q==0:
        return 0
    elif p==0:
        return q
    elif q==0:
        return p
    else:
        if p[0] > q[0]:
            temp = p
            p = q
            q = temp
        r = []

        h=(q[1]-p[1])*MI(q[0]-p[0],P) % P

        r.append((h**2-p[0]-q[0])%P)
        r.append((h*(p[0]-r[0])-p[1])%P)

        return (r[0],r[1])

# print(EC_add(0,0))
# print(EC_add((1,60),0))
# print(EC_add(0,(15,7)))
# print(EC_add((1,60),(15,7)))

def EC_double(p):
    r = []
    h=(3*p[0]**2+A)*MI(2*p[1],P)%P
    r.append((h**2-2*p[0])%P)
    r.append((h*(p[0]-r[0])-p[1])%P)
    return (r[0],r[1])

# print(EC_double((1,5)))
# print(EC_double(BASE_POINT))

def EC_multiply(s,p):
    n = p
    r = 0
    bins = bin(s)[2:]
    lens = len(bins)

    for i in reversed(range(lens)):
        if bins[i] == '1':
            r = EC_add(r,n)
        n = EC_double(n)

    return r


# # Assert that 2P = P + P
# print(EC_multiply(2, BASE_POINT) == EC_double(BASE_POINT))
# # Assert that 4P = 3P + 1P
# print(EC_multiply(4, BASE_POINT) == EC_add(EC_multiply(3, BASE_POINT), EC_multiply(1, BASE_POINT)))
# print(EC_add(EC_multiply(1, BASE_POINT), EC_multiply(6, BASE_POINT)))
# print(EC_multiply(7, BASE_POINT))
# print(EC_double(EC_multiply(5, BASE_POINT)))

# 产生256位整数的，16进制32个字节
def G_private_key():
    return int(secrets.token_hex(32), 16)

# 生成私钥
def G_public_key(private_key):
   return EC_multiply(private_key, BASE_POINT)


def Rp(key):
    if key[1] % 2 == 0:
        parity = '02'
    else:
        parity = '03'

    return parity + hex(key[0])[2:]

def G_key_pair():
    Flag = True
    private_key = G_private_key()
    public_key =G_public_key(private_key)
    # if(Flag):
    #     print("私钥为: " + str(private_key))
    #     print("私钥的十六进制形式为: " + str(hex(private_key))[2:])
    #     print("公钥为: " + str(public_key[0]) + str(public_key[1]))
    #     print("公钥的十六进制形式为: " + "04" + hex(public_key[0])[2:] + hex(public_key[1])[2:])
    #     print("压缩后的公钥为: " + Rp(public_key))
    return (private_key, G_public_key(private_key))


# (pkey,Pkey) = G_key_pair()

# 对信息进行双层加密
def D_hash(msg):
    h_m = sha256(msg.encode('utf-8')).hexdigest()
    h_m = sha256(h_m.encode('utf-8')).hexdigest()
    return int(h_m,16)

# print(D_hash("123456"))


# 利用私钥对信息内容进行签名
def sign(pkey,msg):
    hmsg = D_hash(msg)
    n  = secrets.randbelow(P) # 生成0到P的随机出
    x = EC_multiply(n,BASE_POINT) # 计算随机数乘基点

    rx = x[0] % N

    proof = MI(n,N)*(hmsg + rx * pkey) % N

    return (rx,proof)

# message = "123456789"
# signature = sign(pkey, message)
#
# print("消息: " + message)
# print("签名: ", end="")
# print(signature)

def verify(Pkey,msg,sign,hmsg=None):
    (rx,s) = sign
    if not hmsg:
        hmsg = D_hash(msg)
    Is = MI(s,N)
    a = EC_multiply(hmsg * Is % N,BASE_POINT)
    b = EC_multiply(rx * Is % N ,Pkey)
    x1 = EC_add(a,b)
    return x1[0] == rx

# if verify(Pkey, message, signature):
#     print("验证成功！！")
# else:
#     print("验证失败！！")

def F_signature(public_key,msg):
    u = secrets.randbelow(P)
    v = secrets.randbelow(P)
    Iv = MI(v,N)
    X2 = EC_add(EC_multiply(u,BASE_POINT),EC_multiply(v,public_key))
    # print("u = ",str(hex(u))[2:])
    # print("v = ",str(hex(v))[2:])
    # print("R = ",(str(hex(X2[0])[2:]),str(hex(X2[1])[2:])))
    forge_rx = X2[0]
    forge_e = forge_rx*u*Iv % N
    forge_s = forge_rx*Iv % N
    forge_sig = (forge_rx,forge_s)
    # print("e' = ", hex(forge_e)[2:])
    # print("s' = ", hex(forge_s)[2:])
    print("伪造签名为：({},{})".format(hex(forge_sig[0])[2:],hex(forge_sig[1])[2:]))
    print("===============利用伪造签名进行认证===============")
    print()
    if verify(public_key,msg,forge_sig,forge_e):
        print("伪造签名通过验证!!!")
        return True

if __name__ =="__main__":
    (pkey1,Pkey1) = G_key_pair()
    print("假定中本聪公钥为:",end=" ")
    print(str(Pkey1[0]) + str(Pkey1[1]))
    print("假定中本聪私钥为:",end=" ")
    print(pkey1)
    msg = "1957746"
    print("消息: " + msg)
    print("原始签名为:", end="")
    signature = sign(pkey1, msg)
    print("({},{})".format(hex(signature[0])[2:],hex(signature[1])[2:]))
    F_signature(Pkey1,msg)