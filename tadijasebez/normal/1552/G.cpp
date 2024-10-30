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

const int N=42;
int n,k;
vector<int> st[N];
void NO(){
	printf("REJECTED\n");
	exit(0);
}
bool ok=true;
vector<int> a;
void Solve(int z){
	//printf("z:%i| ",z);
	//for(int i:a)printf("%i ",i);
	//printf("\n");
	if(z>k){
		for(int i=0;i<n;i++){
			if(a[i]==-1)NO();
			if(i>=1&&a[i]<a[i-1])NO();
		}
		return;
	}
	int cnt0=0,cntu=0;
	for(int i:st[z]){
		if(a[i]==0)cnt0++;
		if(a[i]==-1)cntu++;
	}
	vector<int> b=a;
	for(int o=cnt0;o<=cnt0+cntu;o++){
		for(int j=0;j<st[z].size();j++){
			if(j<o)a[st[z][j]]=0;
			else a[st[z][j]]=1;
		}
		Solve(z+1);
	}
	a=b;
}
int main(){
	rd(n,k);
	if(n==1){
		printf("ACCEPTED\n");
		return 0;
	}
	for(int i=1;i<=k;i++){
		int q=ri();
		while(q--)st[i].pb(ri()-1);
	}
	a=vector<int>(n,-1);
	Solve(1);
	if(ok)printf("ACCEPTED\n");
	else printf("REJECTED\n");
	return 0;
}