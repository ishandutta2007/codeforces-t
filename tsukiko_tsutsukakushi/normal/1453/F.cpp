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
    int n; cin >> n;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<vector<int>> dp(n, vector<int>(n, inf));
    rep(j, n) dp[0][j] = 0;
    for(int i = 1; i < n; ++ i) {
        int cnt = 0;
        for(int j = i - 1; j >= 0; -- j) {
            if(j + a[j] >= i) {
                chmin(dp[i][j + a[j]], dp[j][i - 1] + cnt);
                ++ cnt;
            }
        }
        for(int x = i; x < n - 1; ++ x) {
            chmin(dp[i][x + 1], dp[i][x]);
        }
    }
    cout << dp[n - 1][n - 1] << "\n";
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}