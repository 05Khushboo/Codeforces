a,b = "",""
def equi(i,j,i1,j1):
    n,f,jk = int(j-i+1),0,i1
    if a[i:j+1] == b[i1:j1+1]:
        return 1
    if n%2 : return 0
    n = int(n/2)
    if equi(i,i+n-1,i1,i1+n-1) and equi(i+n,j,i1+n,j1) :
        return 1
    if equi(i,i+n-1,i1+n,j1) and equi(i+n,j,i1,i1+n-1) : 
        return 1
    return 0
a,b = raw_input(),raw_input()
s = len(a) - 1
if (equi(0,s,0,s)) : print "YES"
else : print "NO"
