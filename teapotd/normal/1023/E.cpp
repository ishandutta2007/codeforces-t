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


bool ask(int a, int b, int x, int y) {
	cout << "? " << a << ' ' << b << ' ' << x << ' ' << y << endl;
	string str; cin >> str;
	return str[0] == 'Y';
}

void run() {
	int n; cin >> n;

	string front, back;

	int x = 1, y = 1;
	
	while (n-x + n-y > n-1) {
		if (x < n && ask(x+1, y, n, n)) {
			x++;
			front.pb('D');
		} else {
			y++;
			front.pb('R');
		}
	}

	int a = n, b = n;
	
	while (a != x || b != y) {
		if (b > y && ask(1, 1, a, b-1)) {
			b--;
			back.pb('R');
		} else {
			a--;
			back.pb('D');
		}
	}

	reverse(all(back));
	cout << "! " << front+back << endl;
}