#include<iostream>
#include<cstdio>
#define int long long
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
int f(int n)
{
	for(int i=2;i*i<=n;i++)if(n%i==0)return i;
	return n;
}
signed main()
{
	int t,n,k;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		n=read();
		k=read();
		if(n%2==0)printf("%lld\n",n+2*k);
		else printf("%lld\n",n+f(n)+2*k-2);
	}
	return 0;
}