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
#define SZ 1234567
const int MOD=1e9+7;
int n,k,a[SZ],g[SZ],cp[SZ];
ll ans=0;
void fz(int l,int r)
{
	if(l==r) return;
	int m=(l+r)>>1;
	fz(l,m); fz(m+1,r);
	g[m+1]=a[m+1];
	for(int i=m+2;i<=r;++i)
		g[i]=max(g[i-1],a[i]);
	g[m]=a[m];
	for(int i=m-1;i>=l;--i)
		g[i]=max(g[i+1],a[i]);
	int cl=m;
	for(int i=m+1;i<=r;++i)
	{
		while(cl>=l&&g[cl]<=g[i])
			++cp[(cl--)%k];
		ans+=cp[i%k]*(ll)g[i];
		ans%=MOD;
	}
	for(int i=l;i<=r;++i) cp[i%k]=0;
	int cr=m+1;
	for(int i=m;i>=l;--i)
	{
		while(cr<=r&&g[cr]<g[i])
			++cp[(cr++)%k];
		ans+=cp[i%k]*(ll)g[i];
		ans%=MOD;
	}
	for(int i=l;i<=r;++i) cp[i%k]=0;
}
int main()
{
	scanf("%d%d",&n,&k); --k;
	for(int i=1;i<=n;++i)
		scanf("%d",a+i);
	fz(1,n);
	ans=(ans%MOD+MOD)%MOD;
	cout<<ans<<"\n";
}