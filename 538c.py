def possible(d,h,d1,h1,mid):
    diff = mid - h
    d = d + diff
    if d>d1 : return 0
    diff = mid - h1
    d = d + diff
    if d>d1 : return 0
    else : return 1
def binary_search(d,h,d1,h1,l,r):
    mid,f= -1,0
    mid = int(mid)
    while(l<=r):
        if(int(mid)==int((l+r)/2)) : break
        mid = int((l+r)/2)
        if(possible(d,h,d1,h1,mid)) : l,f = mid,1
        else : r = mid;
    if(possible(d,h,d1,h1,mid+1)) : mid,f = mid+1,1
    if(f) : return mid
    else : return -1
n,m = list(int(x) for x in raw_input().split())
d,h = list(int(x) for x in raw_input().split())
ans,f = -1,0
for i in xrange(0,m-1):
    d1,h1 = list(int(x) for x in raw_input().split())
    mx = binary_search(d,h,d1,h1,max(h,h1),1E9)
    if(mx!=-1) : ans = max(ans,mx)
    else : f = 1
    d,h=d1,h1
if f == 0 : print ans
else : print "IMPOSSIBLE"

  
