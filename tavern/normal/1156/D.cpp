/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 2e5 + 5;

int n;
int f[maxn][2], g[maxn][2];
ll ans = 0;
vector<pii> vec[maxn];

void dfs(int u, int p){
	f[u][0] = f[u][1] = 1;
	FOR(i, 0, vec[u].size()){
		int v = vec[u][i].fst,
			w = vec[u][i].snd;
		if(v == p)
			continue;
		dfs(v, u);
		f[u][w] += f[v][w];
	}
	return;
}

void dfs2(int u, int p){
	FOR(i, 0, vec[u].size()){
		int v = vec[u][i].fst;
		int w = vec[u][i].snd;
		if(v == p)
			continue;
		g[v][0] = g[v][1] = 1;
		if(w)
			g[v][1] += g[u][1] + f[u][1] - f[v][1] - 1;
		else
			g[v][0] += g[u][0] + f[u][0] - f[v][0] - 1;
		dfs2(v, u);
	}
	return;
}

int main(){
	scanf("%d", &n);
	FOR(i, 1, n){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		--u; --v;
		vec[u].PB(MP(v, w));
		vec[v].PB(MP(u, w));
	}
	g[0][0] = g[0][1] = 1;
	dfs(0, -1);
	dfs2(0, -1);
	FOR(i, 0, n){
		ans += 1ll * f[i][1] * g[i][0];
		ans += 1ll * f[i][0] * g[i][1];
		ans += 1ll * (f[i][0] - 1) * (f[i][1] - 1);
	}
	ans -= n << 1;
	printf("%lld\n", ans);
	return 0;
}