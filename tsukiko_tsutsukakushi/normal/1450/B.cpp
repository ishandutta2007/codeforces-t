/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
    int n, k; cin >> n >> k;
    vector<int> x(n), y(n);
    rep(i, n) {
        cin >> x[i] >> y[i];
    }
    rep(i, n) {
        bool ok = 1;
        rep(j, n) {
            if(i == j) continue;
            if(abs(x[i] - x[j]) + abs(y[i] - y[j]) > k) ok = 0;
        }
        if(ok) {
            cout << 1 << "\n";
            return;
        }
    }
    cout << -1 << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}