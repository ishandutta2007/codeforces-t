#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=3050;
vector<pii> E[N];
int ans;
int sub[N],dp[N];

void DFS(int u,int p){
	sub[u]=0;
	int best=0;
	for(auto e:E[u])if(e.first!=p){
		int v=e.first;
		DFS(v,u);
		int now=sub[v];
		if(e.second==0)now++;
		sub[u]+=now;
		ckmn(best,dp[v]-now+e.second);
	}
	dp[u]=sub[u]+best;
}

void Solve(int u){
	DFS(u,0);
	int fir=0,sec=0;
	for(auto e:E[u]){
		int v=e.first;
		int now=sub[v];
		if(e.second==0)now++;
		int tmp=dp[v]-now+e.second;
		if(tmp<fir)sec=fir,fir=tmp;
		else ckmn(sec,tmp);
	}
	ckmn(ans,sub[u]+fir+sec);
}

int main(){
	int n=ri();
	for(int i=1;i<n;i++){
		int u,v;rd(u,v);
		E[u].pb({v,1});
		E[v].pb({u,0});
	}
	ans=n-1;
	for(int i=1;i<=n;i++)Solve(i);
	printf("%i\n",ans);
	return 0;
}