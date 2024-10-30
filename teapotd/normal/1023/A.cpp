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


void run() {
	int n, m; cin >> n >> m;
	string s, t; cin >> s >> t;
	bool has = false;

	rep(i, 0, sz(s)) {
		if (s[i] == '*') { has = 1; break; }
		if (i >= sz(t) || s[i] != t[i]){
			cout << "NO\n";
			return;
		}
	}

	reverse(all(s));
	reverse(all(t));

	rep(i, 0, sz(s)) {
		if (s[i] == '*') break;
		if (i >= sz(t) || s[i] != t[i]){
			cout << "NO\n";
			return;
		}
	}

	if ((has && sz(s)-1 > sz(t)) || (!has && sz(s) != sz(t)))
		cout << "NO\n";
	else
		cout << "YES\n";
}