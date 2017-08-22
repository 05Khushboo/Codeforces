a,b = "",""
def equi(s):
    n = len(s)
    if n%2 : return s
    n = int(n/2)
    s1,s2 = equi(s[:-n]),equi(s[n:])
    if s1>s2 : return s1+s2
    else : return s2+s1

a,b = raw_input(),raw_input()
if (equi(a)==equi(b)) : print "YES"
else : print "NO"
