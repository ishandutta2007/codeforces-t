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
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
template<typename T1,typename T2> void chkmin(T1 &x,T2 y){if(x>y) x=y;}
template<typename T1,typename T2> void chkmax(T1 &x,T2 y){if(x<y) x=y;}
typedef pair<int,int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
inline void debug(int x){fprintf(stderr,"ycx has aked ioi %d times\n",x);}
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
	template<typename T> void print(T x,char c){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);putc(c);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXV=1e7;
const int MAXN=5e5;
int mnp[MAXV+5],a1[MAXN+5],a2[MAXN+5];
bitset<MAXV+5> vis;
int pr[MAXV/10+5],prcnt=0;
void sieve(int n){
	for(int i=2;i<=n;i++){
		if(!vis.test(i)) mnp[i]=i,pr[++prcnt]=i;
		for(int j=1;j<=prcnt&&pr[j]*i<=n;j++){
			vis[pr[j]*i]=1;mnp[pr[j]*i]=pr[j];
			if(i%pr[j]==0) break;
		} 
	}
}
int main(){
	sieve(MAXV);int n;scanf("%d",&n);
	for(int i=1,x;i<=n;i++){
		scanf("%d",&x);int tmp=mnp[x],t=x;
		while(mnp[x]==tmp&&x^1) x/=mnp[x];
		if(x==1) a1[i]=a2[i]=-1;
		else a1[i]=x,a2[i]=tmp;
	}
	for(int i=1;i<=n;i++) printf("%d%c",a1[i]," \n"[i==n]);
	for(int i=1;i<=n;i++) printf("%d%c",a2[i]," \n"[i==n]);
	return 0;
}