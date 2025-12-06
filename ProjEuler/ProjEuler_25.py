f=[1]*100000
f[1]=1
f[2]=1
c=0
b=10**999
for i in range(3,100000):
    f[i]=f[i-1]+f[i-2]
    if f[i]>b:
        print(i)
        exit()
