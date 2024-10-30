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
#define VIZ {printf("digraph G{\n"); for(int i=1;i<=n;i++) for es(i,e) printf("%d->%d;\n",i,vb[e]); puts("}");}
#define VIZ2 {printf("graph G{\n"); for(int i=1;i<=n;i++) for es(i,e) if(vb[e]>=i)printf("%d--%d;\n",i,vb[e]); puts("}");}
#define SZ 666666
int a,b,c,m;
vector<int> vs[2];
int main()
{
	scanf("%d%d%d%d",&a,&b,&c,&m);
	for(int i=1;i<=m;i++)
	{
		int x;char s[6];
		scanf("%d%s",&x,s);
		if(s[0]=='U') vs[0].pb(x);
		else vs[1].pb(x);
	}
	sort(vs[0].begin(),vs[0].end());
	sort(vs[1].begin(),vs[1].end());
	int p[2]={0,0};ll ans=0;
	for(int i=1;i<=a;i++)
	{
		if(p[0]>=vs[0].size()) continue;
		ans+=vs[0][p[0]++];
	}
	for(int i=1;i<=b;i++)
	{
		if(p[1]>=vs[1].size()) continue;
		ans+=vs[1][p[1]++];
	}
	for(int i=1;i<=c;i++)
	{
		if(p[1]>=vs[1].size()&&p[0]>=vs[0].size())
			break;
		if(p[1]>=vs[1].size()) ans+=vs[0][p[0]++];
		else if(p[0]>=vs[0].size()) ans+=vs[1][p[1]++];
		else if(vs[0][p[0]]<vs[1][p[1]])
			ans+=vs[0][p[0]++];
		else ans+=vs[1][p[1]++];
	}
	printf("%d %lld\n",p[0]+p[1],ans);
}