/**
 *    author:  otera    
**/
#include<iostream>
#include<string>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<deque>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
#include<cassert>
using namespace std;

#define int long long
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60 ;
const ll mod=1e9+7 ;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef complex<ld> Point;
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<int, int> P;
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
#define pb push_back
#define debug(x)  cerr << #x << " = " << (x) << endl;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

void solve() {
	int n, k; cin >> n >> k;
    vector<int> a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vector<bool> check(n, 0);
    rep(i, n) {
        if(i - 1 >= 0 && i + 1 < n) {
            if(a[i - 1] < a[i] && a[i] > a[i + 1]) {
                check[i] = 1;
            }
        }
    }
    int ans = 0, tmp = 0;
    for(int i = 1; i < k - 1; ++ i) {
        // if(a[i - 1] < a[i] && a[i] > a[i + 1]) {
        //     ++ tmp;
        // }
        if(check[i]) ++tmp;
    }
    int res = tmp;
    for(int i = 1; i + k <= n; ++ i) {
        // if(i - 2 >= 0 && a[i - 2] < a[i - 1] && a[i - 1] > a[i]) {
        //     -- tmp;
        // }
        // if(i + k - 1 < n && a[i + k - 3] < a[i + k - 2] && a[i + k - 2] > a[i + k - 1]) {
        //     ++ tmp;
        // }
        // if(chmax(res, tmp)) {
        //     ans = i;
        // }
        if(check[i]) --tmp;
        if(check[i + k - 2]) ++tmp;
        if(chmax(res, tmp)) {
            ans = i;
        }
    }
    cout << res + 1 << " " << ans + 1 << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}