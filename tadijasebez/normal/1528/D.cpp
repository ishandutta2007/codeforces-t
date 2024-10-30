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

const int N=605;
const ll inf=1e18;
ll w[N][N];
bool was[N];
ll dist[N];
int main(){
	int n,m;
	rd(n,m);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			w[i][j]=inf;
		}
	}
	for(int i=1;i<=m;i++){
		int a,b,c;
		rd(a,b,c);
		w[a][b]=c;
	}
	for(int i=0;i<n;i++){
		for(int t=0;t<2;t++){
			for(int j=0;j<n;j++){
				ckmn(w[i][(j+1)%n],w[i][j]+1);
			}
		}
	}
	for(int src=0;src<n;src++){
		for(int i=0;i<n;i++){
			was[i]=false;
			dist[i]=inf;
		}
		dist[src]=0;
		for(int o=0;o<n;o++){
			int u=-1;
			for(int i=0;i<n;i++){
				if(!was[i]){
					if(u==-1||dist[u]>dist[i])u=i;
				}
			}
			was[u]=true;
			for(int i=0;i<n;i++){
				int v=(dist[u]+i)%n;
				if(!was[v]&&dist[v]>dist[u]+w[u][i]){
					dist[v]=dist[u]+w[u][i];
				}
			}
		}
		for(int i=0;i<n;i++)printf("%lld ",dist[i]);
		printf("\n");
	}
	return 0;
}