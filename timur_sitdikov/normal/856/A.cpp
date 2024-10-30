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

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const int INF = 1e9;
const ll MOD = 1e9 + 7;

const int MAXN = 2e6 + 5;

int used[MAXN];

int dif_used[MAXN];

int vals[MAXN];

vi ans;

void solve(){
	int n;
	ans.clear();
	REP(i, 0, MAXN){
		used[i] = 0;
	}
	scanf("%d", &n);
	REP(i, 0, n){
		scanf("%d", &vals[i]);
	}
	sort(vals, vals + n);
	int cur = 1;
	int lim = 1e6;
	REP(i, 0, n){
		for(; cur <= lim && used[cur]; cur++);
		if (cur > lim){
			printf("NO\n");
			return;
		}
		ans.pb(cur);
		REP(j, 0, n){
			REP(k, j + 1, n){
				used[cur + vals[k] - vals[j]] = 1;
			}
		}
		cur++;
	}
	printf("YES\n");
	REP(i, 0, SZ(ans)){
		printf("%d ", ans[i]);
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