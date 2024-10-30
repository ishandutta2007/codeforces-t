#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <string>
#include <bitset>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <sstream>
#include <stack>
#include <iomanip>
using namespace std;
#define pb push_back
#define mp make_pair
typedef pair<int,int> pii;
typedef long long ll;
typedef double ld;
typedef vector<int> vi;
#define fi first
#define se second
#define fe first
#define FO(x) {freopen(#x".in","r",stdin);freopen(#x".out","w",stdout);}
#define Edg int M=0,fst[SZ],vb[SZ],nxt[SZ];void ad_de(int a,int b){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;}void adde(int a,int b){ad_de(a,b);ad_de(b,a);}
#define Edgc int M=0,fst[SZ],vb[SZ],nxt[SZ],vc[SZ];void ad_de(int a,int b,int c){++M;nxt[M]=fst[a];fst[a]=M;vb[M]=b;vc[M]=c;}void adde(int a,int b,int c){ad_de(a,b,c);ad_de(b,a,c);}
#define es(x,e) (int e=fst[x];e;e=nxt[e])
#define esb(x,e,b) (int e=fst[x],b=vb[e];e;e=nxt[e],b=vb[e])
#define SZ 666666
int n,m,ans=0,ff[SZ],fa[SZ],dep[SZ]; Edg
bool vis[SZ],te[SZ];
vector<int> cx;
int gf(int x) {return ff[x]?ff[x]=gf(ff[x]):x;}
void dfs(int x)
{
	vis[x]=1; cx.pb(x);
	for esb(x,e,b) if(!vis[b])
		te[e]=te[e^1]=1,
		dep[b]=dep[x]+1,
		fa[b]=x,dfs(b);
}
namespace Tr2
{
Edg
bool big[SZ];
int dis[SZ],dis2[SZ]; pii mx;
void dfs(int*d,int x)
{
	mx=max(mx,pii(d[x],x));
	for esb(x,e,b) if(d[b]==-1)
		d[b]=d[x]+1,dfs(d,b);
}
void doit()
{
	for(int i=1;i<=n;++i)
		dis[i]=dis2[i]=-1;
	for(int i=1;i<=n;++i)
		if(big[i]&&dis[i]==-1)
		{
			mx=pii(-1,-1);
			dis[i]=1; dfs(dis,i);
			int g=mx.se; mx=pii(-1,-1);
			dis2[g]=1; dfs(dis2,g);
			ans-=mx.fi;
		}
}
}
namespace Tr
{
Edg
int du[SZ];
void doit()
{
	for(int i=1;i<=n;++i) if(du[i]>=2)
	{
		++ans; Tr2::big[i]=1;
		for esb(i,e,b) if(b>i&&du[b]>=2)
			Tr2::adde(i,b);
	}
}
}
void work(int r)
{
	cx.clear(); dep[r]=1; dfs(r);
	for(unsigned _=0;_<cx.size();++_)
	{
		int x=cx[_];
		for esb(x,e,b) if(!te[e]&&dep[x]<dep[b])
		{
			for(int g=gf(b);dep[g]>dep[x];g=gf(g))
				ff[g]=fa[g],++ans;
		}
	}
	for(unsigned _=0;_<cx.size();++_)
	{
		int x=cx[_];
		for esb(x,e,b)
			if(b>x&&gf(x)!=gf(b))
				Tr::adde(gf(x),gf(b)),
				++Tr::du[gf(x)],
				++Tr::du[gf(b)];
	}
}
int main()
{
	scanf("%d%d",&n,&m); M=1;
	for(int i=1,a,b;i<=m;++i)
		scanf("%d%d",&a,&b),adde(a,b);
	for(int i=1;i<=n;++i) if(!vis[i])
		++ans,work(i);
	--ans; Tr::doit(); Tr2::doit();
	printf("%d\n",ans);
}