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
const int MAXN=3e5;
const int LOG_N=18;
int n,a[MAXN+5],dp[MAXN+5],from[MAXN+5],st[MAXN+5][LOG_N+2];
int query(int l,int r){
	if(l>r) return 0;
	int k=31-__builtin_clz(r-l+1);
	return max(st[l][k],st[r-(1<<k)+1][k]);
}
char s[MAXN+5];
void solve(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]),st[i][0]=i+a[i];
	for(int i=1;i<=LOG_N;i++) for(int j=1;j+(1<<i)-1<=n;j++)
		st[j][i]=max(st[j][i-1],st[j+(1<<i-1)][i-1]);
	for(int i=1;i<=n;i++) from[i]=dp[i]=0;
	for(int i=1;i<=n;i++){
		if(dp[i-1]<i) dp[i]=dp[i-1];
		else{
			if(!a[i]) from[i]=i,dp[i]=dp[i-1];
			else from[i]=i,dp[i]=max(dp[i-1],i+a[i]);
		}
		int l=0,r=i-1,t=i;
		while(l<=r){
			int mid=l+r>>1;
			if(dp[mid]>=i-a[i]-1) t=mid,r=mid-1;
			else l=mid+1;
		} //printf("%d\n",t);
		if(t!=i){
			if(dp[i]<max(query(t+1,i-1),max(dp[t],i-1)))
				dp[i]=max(query(t+1,i-1),max(dp[t],i-1)),from[i]=t;
		}
//		printf("%d %d\n",i,dp[i]);
	} if(dp[n]<n) return puts("NO"),void();
	puts("YES");
	int cur=n;
	while(cur){
		if(from[cur]==cur) s[cur]='R',cur--;
		else{
			s[cur]='L';
			for(int i=from[cur]+1;i<cur;i++) s[i]='R';
			cur=from[cur];
		}
	} s[n+1]='\0';printf("%s\n",s+1);
}
int main(){
	int qu;scanf("%d",&qu);
	while(qu--) solve();
	return 0;
}