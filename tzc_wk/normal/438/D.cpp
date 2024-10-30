#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a,0,sizeof(a))
#define fill1(a) memset(a,-1,sizeof(a))
#define fillbig(a) memset(a,63,sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
namespace fastio{
	#define FILE_SIZE 1<<23
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc(x%10^48);}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=1e5;
int n,qu,a[MAXN+5];
struct node{int l,r,mx;ll sum;} s[MAXN*4+5];
void pushup(int k){
	s[k].mx=max(s[k<<1].mx,s[k<<1|1].mx);
	s[k].sum=s[k<<1].sum+s[k<<1|1].sum;
}
void build(int k=1,int l=1,int r=n){
	s[k].l=l;s[k].r=r;if(l==r){s[k].mx=s[k].sum=a[l];return;}
	int mid=l+r>>1;build(k<<1,l,mid);build(k<<1|1,mid+1,r);pushup(k);
}
void modify(int k,int l,int r,int mod){
	if(s[k].mx<mod||s[k].r<l||s[k].l>r) return;
	if(s[k].l==s[k].r){s[k].mx%=mod;s[k].sum%=mod;return;}
	modify(k<<1,l,r,mod);modify(k<<1|1,l,r,mod);pushup(k);
}
void assign(int k,int p,int x){
	if(s[k].l==s[k].r){s[k].mx=s[k].sum=x;return;}
	int mid=s[k].l+s[k].r>>1;
	if(p<=mid) assign(k<<1,p,x);else assign(k<<1|1,p,x);
	pushup(k);
}
ll query(int k,int l,int r){
	if(l<=s[k].l&&s[k].r<=r) return s[k].sum;
	int mid=s[k].l+s[k].r>>1;
	if(r<=mid) return query(k<<1,l,r);
	else if(l>mid) return query(k<<1|1,l,r);
	else return query(k<<1,l,mid)+query(k<<1|1,mid+1,r);
}
int main(){
	scanf("%d%d",&n,&qu);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	build();
	while(qu--){
		int opt;scanf("%d",&opt);
		if(opt==1){int l,r;scanf("%d%d",&l,&r);printf("%lld\n",query(1,l,r));}
		else if(opt==2){int l,r,mod;scanf("%d%d%d",&l,&r,&mod);modify(1,l,r,mod);}
		else{int k,x;scanf("%d%d",&k,&x);assign(1,k,x);}
	}
	return 0;
}