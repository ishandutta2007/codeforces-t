#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

struct Vert {
	Vi E;
	bool visited{false};
};

int n, m, q;
vector<Vert> G;

void dfs(int i) {
	if (G[i].visited) return;
	G[i].visited = true;
	each(e, G[i].E) dfs(e);
}

void run() {
	cin >> n >> m >> q;
	G.resize(n+m);

	rep(i, 0, q) {
		int a, b; cin >> a >> b;
		a--; b += n-1;
		G[a].E.pb(b);
		G[b].E.pb(a);
	}

	int ret = -1;

	rep(i, 0, n+m) if (!G[i].visited) {
		dfs(i);
		ret++;
	}

	cout << ret << endl;
}