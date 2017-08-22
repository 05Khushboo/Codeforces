a = raw_input()
n = len(a)
b = ""
for i in range(0,n):
    if len(b)==0 : b+=a[i]
    elif b[-1]==a[i] : b = b[:-1]
    else : b+=a[i]
if len(b)== 0 : print "Yes"
else : print "No"
