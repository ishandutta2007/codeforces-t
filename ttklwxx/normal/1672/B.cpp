#include<iostream>
#include<cstdio>
#include<cstring>
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
char s[200005];
int main()
{
	int t,n,sl;
	bool flag;
	t=read();
	for(int greg=1;greg<=t;greg++)
	{
		scanf("%s",s+1);
		n=strlen(s+1);
		if(s[n]=='A')
		{
			printf("NO\n");
			continue;
		}
		sl=0;
		flag=true;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='B')sl--;
			else sl++;
			if(sl<0)
			{
				printf("NO\n");
				flag=false;
				break;
			}
		}
		if(flag==false)continue;
		printf("YES\n");
	} 
	return 0;
}