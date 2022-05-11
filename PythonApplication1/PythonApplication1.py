import time
def Func(i):
    if i==0: return 0
    b=3
    c=3
    a=0
    for j in range(100000000):
        a+=2*b+c-i
    return Func(i-1)+a
t=time.time()
print(Func(5))
print(time.time()-t)
