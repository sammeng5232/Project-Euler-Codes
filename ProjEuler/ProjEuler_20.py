p=1
for i in range(2,101):
    p*=i
p=str(p)
l=len(p)
s=0
for i in range(l):
    s+=int(p[i])
print(s)
