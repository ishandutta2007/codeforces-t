a,b,c=map(int,input().split())
if(b>=a+1):
    b=a+1
else:
    a=b-1
if(c>=b+1):
    c=b+1
else:
    b=c-1
if(b>=a+1):
    b=a+1
else:
    a=b-1
if(c>=b+1):
    c=b+1
else:
    b=c-1
print(a+b+c)