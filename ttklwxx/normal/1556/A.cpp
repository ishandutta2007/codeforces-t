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
signed main()
{
	int t,c,d;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		c=read();
		d=read();
		if((c+d)%2==1)printf("-1\n");
		else if(c==0&&d==0)printf("0\n");
		else if(c==d)printf("1\n");
		else printf("2\n");
	}
	return 0;
}