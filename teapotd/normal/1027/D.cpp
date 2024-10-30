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
	int next, cost, seen{0};
};

vector<Vert> G;

void run() {
	int n; cin >> n;
	G.resize(n);

	each(v, G) cin >> v.cost;
	each(v, G) {
		cin >> v.next;
		v.next--;
	}

	ll ans = 0;

	rep(i, 0, n) if (G[i].seen == 0) {
		int v = i;
		while (G[v].seen == 0) {
			G[v].seen = 1;
			v = G[v].next;
		}

		if (G[v].seen != 2) {
			int m = INT_MAX;
			while (G[v].seen == 1) {
				m = min(m, G[v].cost);
				G[v].seen = 2;
				v = G[v].next;
			}

			ans += m;
		}

		v = i;
		while (G[v].seen < 2) {
			G[v].seen = 2;
			v = G[v].next;
		}
	}

	cout << ans << endl;
}