#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
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
#define j0 gray_cat_j0

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 16;
const int INF = 1e9 + 10;
ll MOD = 1e9 + 7;

const int MAXN = 2e5 + 5;

vi g[MAXN];
vi sz;
int cnt;

int used[MAXN];

void dfs(int s) {
	used[s] = 1;
	cnt++;
	REP(i, 0, SZ(g[s])) {
		int to = g[s][i];
		if (!used[to]) {
			dfs(to);
		}
	}
}

void solve(){
	int n, m;
	scanf("%d%d%lld", &n, &m, &MOD);
	REP(i, 0, m) {
		int a, b;
		scanf("%d%d", &a, &b);
		g[a].pb(b);
		g[b].pb(a);
	}
	REPN(i, 1, n) {
		if (!used[i]) {
			cnt = 0;
			dfs(i);
			sz.pb(cnt);
		}
	}
	
	if (SZ(sz) == 1) {
		printf("%lld\n", 1 % MOD);
		return;
	}
	
	ll ans = 1ll % MOD;
	REP(i, 1, SZ(sz) - 1) {
		ans = (ans * n) % MOD;
	}
	REP(i, 0, SZ(sz)) {
		ans = (ans * sz[i]) % MOD;
	}
	printf("%lld\n", ans);
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