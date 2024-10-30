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

int per[MAXN];
int per_inv[MAXN];

set<int> not_used;

void my_set(int from, int to) {
	per[from] = to;
	per_inv[to] = from;
	not_used.erase(to);
}

void solve(){
	int n;
	scanf("%d", &n);
	REPN(i, 1, n) {
		per_inv[i] = 0;
	}
	REPN(i, 1, n) {
		scanf("%d", &per[i]);
		per_inv[per[i]] = i;
	}
	not_used.clear();
	REPN(i, 1, n) {
		if (!per_inv[i]) {
			not_used.insert(i);
		}
	}
	int ans = n - SZ(not_used);
	REPN(i, 1, n) {
		if (per_inv[per[i]] == i) {
			continue;
		}
		int c1 = *not_used.begin();
		if (c1 != i) {
			my_set(i, c1);
		} else {
			if (SZ(not_used) > 1) {
				c1 = *not_used.upper_bound(c1);
				my_set(i, c1);
			} else {
				int b = per_inv[per[i]];
				per[b] = i;
				break;
			}
		}
	}
	printf("%d\n", ans);
	REPN(i, 1, n) {
		printf("%d ", per[i]);
	}
	putchar('\n');
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    cin >> t;
    while(t--){
        solve();
    }
}