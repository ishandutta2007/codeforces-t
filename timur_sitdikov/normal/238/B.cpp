#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef double DOUBLE;
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

#define x0 gray_cat_x0
#define y0 gray_cat_y0
#define x1 gray_cat_x1
#define y1 gray_cat_y1
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
// const ll MOD = 1e9 + 7;
const ll MOD = 998244353;

const int MAXN = 3e5 + 5;

pii pp[MAXN];
int ans[MAXN];

vi mx, mn;

void solve(){
	int n, h;
	scanf("%d%d", &n, &h);
	REP(i, 0, n) {
		scanf("%d", &pp[i]._1);
		pp[i]._2 = i;
	}
	sort(pp, pp + n);
	int v_1 = pp[n - 1]._1 + pp[n - 2]._1 - pp[0]._1 - pp[1]._1;
	mx.pb(pp[n - 1]._1 + pp[n - 2]._1);
	mx.pb(pp[n - 1]._1 + pp[0]._1 + h);
	mn.pb(pp[0]._1 + pp[1]._1 + h);
	if (n >= 3) {
		mn.pb(pp[1]._1 + pp[2]._1);
	}
	SORT(mx);
	SORT(mn);
	int v_2 = mx.back() - mn.front();
	int res = v_1;
	if (v_2 < v_1) {
		res = v_2;
		ans[pp[0]._2] = 1;
	}
	printf("%d\n", res);
	REP(i, 0, n) {
		printf("%d ", ans[i] + 1);
	}
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }
}