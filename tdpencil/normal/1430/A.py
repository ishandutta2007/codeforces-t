for n in[*open(0)][1:]:n=int(n);print(*([[[n//3,(n-7)//3,(n-5)//3][n%3],n%3//2,n%3%2],[-1]][n in[1,2,4]]))