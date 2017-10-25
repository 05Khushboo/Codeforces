n= int(input())
s= raw_input()
dic  = { '4':'322', '6':'53', '8':'7222', '9':'7332' }
for x in dic:
    s =  s.replace(x,dic[x])
mylist =list(s)
mylist.sort(reverse=True)
newlist=[]
for x in range(len(mylist)):
    if(mylist[x]!='0' and mylist[x]!='1'):
        newlist.append(mylist[x])
print "".join(x for x in newlist)

 
