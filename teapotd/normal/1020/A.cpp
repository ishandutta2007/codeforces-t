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

void run() {
	int n, h, a, b, k;
	cin >> n >> h >> a >> b >> k;

	while (k--) {
		int ta, fa, tb, fb;
		cin >> ta >> fa >> tb >> fb;

		if (fa > fb) {
			swap(ta, tb);
			swap(fa, fb);
		}

		if (ta == tb) {
			cout << fb-fa << '\n';
		} else if (a <= fb && fa <= b) {
			cout << fb-fa + abs(tb-ta) << '\n';
		} else {
			int x = abs(fb-a) + abs(fa-a), y = abs(fb-b) + abs(fa-b);
			cout << min(x, y) + abs(tb-ta) << '\n';
		}
	}
}