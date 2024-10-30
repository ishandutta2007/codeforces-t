#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fz(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define ffe(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
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
namespace fastio{
	#define FILE_SIZE 1<<25
	char rbuf[FILE_SIZE],*p1=rbuf,*p2=rbuf,wbuf[FILE_SIZE],*p3=wbuf;
	inline char getc(){return p1==p2&&(p2=(p1=rbuf)+fread(rbuf,1,FILE_SIZE,stdin),p1==p2)?-1:*p1++;}
	inline void putc(char x){(*p3++=x);}
	template<typename T> void read(T &x){
		x=0;char c=getchar();T neg=0;
		while(!isdigit(c)) neg|=!(c^'-'),c=getchar();
		while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
		if(neg) x=(~x)+1;
	}
	template<typename T> void recursive_print(T x){if(!x) return;recursive_print(x/10);putc((x%10)+'0');}
	template<typename T> void print(T x){if(!x) putc('0');if(x<0) putc('-'),x=~x+1;recursive_print(x);}
	void print_final(){fwrite(wbuf,1,p3-wbuf,stdout);}
}
const int MAXN=5000;
int n,a[MAXN+5],sum[MAXN+5];
void solve(){
	memset(sum,0,sizeof(sum));
	scanf("%d",&n);ll ret=0;
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	int need=0;
	for(int i=1;i<=n;i++){
		need+=sum[i];
//		printf("%d %d\n",i,need);
		if(need>a[i]-1){
			sum[i+2]++;if(i+a[i]+1<=n) sum[i+a[i]+1]--;
			sum[i+1]+=need-(a[i]-1);
			sum[i+2]-=need-(a[i]-1);
		} else {
			ret+=a[i]-1-need;
//			printf("add %d %d\n",i,a[i]-1-need);
			sum[i+2]++;if(i+a[i]+1<=n) sum[i+a[i]+1]--;
		}
	} printf("%lld\n",ret);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}