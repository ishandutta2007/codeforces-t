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

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct Vert {
	Vi E;
};

vector<Vert> G;
int ans = 0;

int dfs(int i, int p, int d) {
	bool color = false;

	each(e, G[i].E) if (e != p) {
		int k = dfs(e, i, d+1);
		d = min(d, k+1);
		if (k > 2) color = true;
	}

	if (color && d >= 2) {
		ans++;
		return 1;
	}
	return d;
}

void run() {
	int n; cin >> n;
	G.resize(n);

	rep(i, 1, n) {
		int a, b; cin >> a >> b;
		G[a-1].E.pb(b-1);
		G[b-1].E.pb(a-1);
	}

	dfs(0, -1, 0);
	cout << ans << endl;
}