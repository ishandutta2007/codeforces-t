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

void run() {
	int n, m, q;
	cin >> n >> m >> q;

	string s, t;
	cin >> s >> t;

	Vi counts(sz(s)+1);
	counts[0] = 0;

	rep(i, 1, sz(s)-sz(t)+2) {
		bool ok = true;
		counts[i] = counts[i-1];

		rep(j, 0, sz(t)) if (s[i+j-1] != t[j]) {
			ok = false;
			break;
		}
		if (ok) counts[i]++;
	}

	while (q--) {
		int l, r;
		cin >> l >> r;
		l--;

		if (r-l < sz(t)) {
			cout << "0\n";
		} else {
			cout << counts[r-sz(t)+1] - counts[l] << '\n';
		}
	}
}