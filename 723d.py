X = [-1,1,0,0]
Y = [0,0,1,-1]
n,m,k = 0,0,0
vi,arr,chain,v,k1 = [],[],[],[],0
import sys
sys.setrecursionlimit(10**6)
def check(x,y):
    if x>=0 and x<n and y>=0 and y<m : return 1
    else : return 0
def dfs(s,s1):
    v[k1].append((s,s1))
    chain[s][s1] = k1
    vi[s][s1] = 1
    for i in range(0,4):
        x = s + X[i]
        y = s1 + Y[i]
        if check(x,y)==1 :
            if vi[x][y]==0 and arr[x][y] == 1 : dfs(x,y)
    return ;
n,m,k = raw_input().split()
n,m,k = int(n),int(m),int(k)
for i in range(0,n):
    arr.append([])
    vi.append([])
    chain.append([])
    x = raw_input()
    for k2 in x:
        vi[i].append(0)
        chain[i].append(0)
        if k2 == "*": arr[i].append(0)
        else : arr[i].append(1)
for i in range(0,n):
    for j in range(0,m):
        if vi[i][j]==0 and arr[i][j] == 1:
            v.append([])
            dfs(i,j)
            k1+=1
a = []
for i in range(0,k1):
    flag = 0
    for j in v[i]:
        x,y = j[0],j[1]
        if x==0 or x==(n-1) or y==0 or y==(m-1) : 
            flag = 1
            break
    if flag==0 :
        a.append((len(v[i]),i))
a.sort()
vis,cnt = [],0
p = len(a) - k
for i in range(0,k1) : vis.append(0)
for i in range(0,p):
    no = a[i][1]
    vis[no] = 1
for i in a:
    idx = i[1]
    for j in v[idx]:
        x,y= j[0],j[1]
        if vis[idx]==1:
            arr[x][y] = 0
            cnt+=1
print cnt
for i in range(0,n):
    s = ""
    for j in range(0,m):
        if arr[i][j]==0  : s+="*"
        else : s+="."
    print s
