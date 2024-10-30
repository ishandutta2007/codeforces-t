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

int a[MAXN], b[MAXN];

void solve(){
	int n, m, ta, tb, k;
	scanf("%d%d%d%d%d", &n, &m, &ta, &tb, &k);
	REP(i, 0, n) {
		scanf("%d", &a[i]);
	}
	REP(i, 0, m) {
		scanf("%d", &b[i]);
	}
	int ans = 0;
	int j = 0;
	if (k >= n || k >= m) {
		printf("-1\n");
		return;
	}
	REPN(i, 0, k) {
		for(; j < m && b[j] < a[i] + ta; j++);
		if (m - j <= k - i) {
			printf("-1\n");
			return;
		}
		ans = max(ans, b[j + k - i] + tb);
	}
	printf("%d\n", ans);
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}