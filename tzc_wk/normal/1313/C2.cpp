//Coded by tzc_wk
/*




D P 




 l l
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define giveup(...) return printf(__VA_ARGS__),0;
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define fillsmall(a) memset(a,0xcf,sizeof(a))
#define mask(a)		(1ll<<(a))
#define maskx(a,x)	((a)<<(x))
#define _bit(a,x)	(((a)>>(x))&1)
#define _sz(a)		((int)(a).size())
#define filei(a)	freopen(a,"r",stdin);
#define fileo(a)	freopen(a,"w",stdout);
#define fileio(a) 	freopen(a".in","r",stdin);freopen(a".out","w",stdout)
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#define put(x)		putchar(x)
#define eoln        put('\n')
#define space		put(' ')
#define y1			y_chenxiaoyan_1
#define y0			y_chenxiaoyan_0
#define int long long
typedef pair<int,int> pii;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')	neg=-1;
		c=getchar();
	}
	while(isdigit(c))	x=x*10+c-'0',c=getchar();
	return x*neg;
}
inline void print(int x){
	if(x<0){
		putchar('-');
		print(abs(x));
		return;
	}
	if(x<=9)	putchar(x+'0');
	else{
		print(x/10);
		putchar(x%10+'0');
	}
}
inline int qpow(int x,int e,int _MOD){
	int ans=1;
	while(e){
		if(e&1)	ans=ans*x%_MOD;
		x=x*x%_MOD;
		e>>=1;
	}
	return ans;
}
int n=read(),a[500005],pre[500005],suf[500005],ans[500005];
stack<pii> stk;
signed main(){
	fz(i,1,n)	a[i]=read();
	fz(i,1,n){
		int dis=1;
		pre[i]=pre[i-1]+a[i];
		while(!stk.empty()&&a[i]<stk.top().se){
			pii tp=stk.top();pre[i]-=tp.fi*(tp.se-a[i]);
			dis+=tp.fi;stk.pop();
		}
//		cout<<"dis="<<dis<<endl;
		stk.push({dis,a[i]});
	}
	while(!stk.empty())	stk.pop();
	fd(i,n,1){
		int dis=1;
		suf[i]=suf[i+1]+a[i];
		while(!stk.empty()&&a[i]<stk.top().se){
			pii tp=stk.top();suf[i]-=tp.fi*(tp.se-a[i]);
			dis+=tp.fi;stk.pop();
		}
//		cout<<"dis="<<dis<<endl;
		stk.push({dis,a[i]});
	}
//	fz(i,1,n)	cout<<pre[i]<<" "<<suf[i]<<endl;
	int csum=0,ind=0;
	fz(i,1,n){
		if(csum<(pre[i]+suf[i]-a[i]))	csum=pre[i]+suf[i]-a[i],ind=i;
	}
	ans[ind]=a[ind];
	fd(i,ind-1,1)	ans[i]=min(ans[i+1],a[i]);
	fz(i,ind+1,n)	ans[i]=min(ans[i-1],a[i]);
	fz(i,1,n)	cout<<ans[i]<<" ";
	return 0;
}