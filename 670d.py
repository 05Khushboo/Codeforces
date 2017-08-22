a,b,n,k,k1=[],[],0,0,0
def possible(no):
    s,p = 0,0
    k = k1
    for i in range(0,n):
        s = a[i] *no
        p = b[i]
        if p < s :
            diff = s - p
            if diff > k :  return 0
            else : k-= diff
    return 1
def binary(l,r):
    mid = -1
    while(l<=r):
        k = k1
        if mid==(l+r)/2 : break;
        mid = int((l+r)/2)
        if possible(mid)==1 : l = mid
        else : r = mid
    return mid
n,k1 = raw_input().split()
n,k1 = int(n),int(k1)
k = k1
x,y = raw_input().split(),raw_input().split()
for i in x:
    p = int(i)
    a.append(p)
for i in y:
    p = int(i)
    b.append(p)
print binary(0,1E10)

