n,m,t1 = list(int(x) for x in raw_input().split())
ans,fact = 0,[]
fact.append(1)
for i in xrange(1,31) : fact.append(i*fact[i-1]);
for j in xrange(4,n+1):
    cnt,t = 0,(t1-j)
    if(t<=0) : break;
    if(t>m) : continue;
    k = fact[m-t]*fact[t];
    cnt = (fact[m]/k);
    k = fact[n-j]*fact[j];
    cnt*=(fact[n]/k);
    ans+=cnt;
print int(ans);

