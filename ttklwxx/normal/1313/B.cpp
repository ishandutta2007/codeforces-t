#include<iostream>
#include<cstdio>
using namespace std;
inline int read()
{
	int n=0,f=1,ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		n=n*10+ch-'0';
		ch=getchar();
	}
	return n*f;
}
int main()
{
	int t,a,b,n;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		a=read();
		b=read();
		printf("%d %d\n",min(n,max(1,a+b+1-n)),min(a+b-1,n));
	}
	return 0;
}