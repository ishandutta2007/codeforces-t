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
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		printf("%d\n",n-(k+1)/2);
		for(int i=(k+1)/2;i<=k-1;i++)printf("%d ",i);
		for(int i=k+1;i<=n;i++)printf("%d ",i);
		printf("\n");
	}
	return 0;
}