def x(a,b):
    if(a>b):
        return(1)
    else:
        return(0)
n=int(input())
a1,a2=map(int,input().split())
b1,b2=map(int,input().split())
c1,c2=map(int,input().split())
if((a1-a2)==(b1-b2)):
    print("NO")
elif((a1+a2)==(b1+b2)):
    print("NO")
elif(a1==b1):
    print("NO")
elif(a2==b2):
    print("NO")
elif((a1-a2)==(c1-c2)):
    print("NO")
elif((a1+a2)==(c1+c2)):
    print("NO")
elif(a1==c1):
    print("NO")
elif(a2==c2):
    print("NO")
else:
    if((x(a1,b1)==x(a1,c1)) and (x(a2,b2)==x(a2,c2))):
        print("YES")
    else:
        print("NO")