#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

set<int> b;

void solve(){
	int n, m;
	ll ans = 0ll;
	scanf("%d%d", &n, &m);
	int mxb = -1, mxb2 = -1;
	REP(i, 0, n) {
		int a;
		scanf("%d", &a);
		b.insert(-a);
		ans += (ll)m * (ll)a;
		if (a >= mxb) {
			mxb2 = mxb;
			mxb = a;
		} else if (a > mxb2) {
			mxb2 = a;
		}
		mxb = max(mxb, a);
	}
	//cout << ans << endl;
	int ming = INF;
	REP(i, 0, m) {
		int a;
		scanf("%d", &a);
		if (a < mxb) {
			printf("-1\n");
			return;
		}
		int d = *b.lower_bound(-a);
		ans += (a - (-d));
		ming = min(ming, a);
	}
	if (ming > mxb) {
		ans += mxb - mxb2;
	}
	cout << ans << endl;
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}