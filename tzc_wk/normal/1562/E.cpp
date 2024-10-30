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
#define mt make_tuple
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
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
	template<typename T> void recursive_print(T x){return (!x)?void():(recursive_print(x/10),putc(x%10^48),void());}
	template<typename T> void print(T x){(!x)&&(putc('0'),0);(x<0)&&(putc('-'),x=~x+1);recursive_print(x);}
	template<typename T> void print(T x,char c){print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5000;
int n,len=0,z[MAXN*2+5],dp[MAXN+5];
char s[MAXN+5],t[MAXN*2+5];
void z_func(){
	int l=0,r=0;memset(z,0,sizeof(z));
	for(int i=2;i<=len;i++){
		z[i]=(i<=r)?(min(r-i+1,z[i-l+1])):0;
		while(i+z[i]<=len&&t[z[i]+1]==t[i+z[i]]) ++z[i];
		if(i+z[i]-1>r) l=i,r=i+z[i]-1;
	}
}
void solve(){
	memset(dp,0,sizeof(dp));
	scanf("%d%s",&n,s+1);int res=0;
	for(int i=1;i<=n;i++){
		len=0;dp[i]=n-i+1;
		for(int j=i;j<=n;j++) t[++len]=s[j];
		t[++len]='#';
		for(int j=1;j<=n;j++) t[++len]=s[j];
		t[len+1]=0;z_func();
//		printf("%s\n",t+1);
//		for(int j=1;j<=len;j++) printf("%d%c",z[j]," \n"[j==len]);
		for(int j=1;j<i;j++){
			int lcp=z[n-i+2+j];
			if(lcp!=n-i+1&&t[lcp+1]>s[j+lcp]) chkmax(dp[i],dp[j]+(n-i-lcp+1));
		} chkmax(res,dp[i]);
	} printf("%d\n",res);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}