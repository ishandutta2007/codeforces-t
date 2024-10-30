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

template<typename T>
vector<T> compress(vector<T> A){
    sort(A.begin(), A.end());
    A.erase(unique(A.begin(), A.end()), A.end());
    return A;
}

void solve() {
	int n, x, m; cin >> n >> x >> m;
    -- x;
    vector<int> y;
    y.pb(0); y.pb(n); y.pb(x); y.pb(x + 1);
    vector<int> l(m), r(m);
    rep(i, m) {
        cin >> l[i] >> r[i];
        -- l[i];
        y.pb(l[i]), y.pb(r[i]);
    }
    auto comy = compress(y);
    int sz = (int)comy.size();
    vector<bool> used(sz + 1, 0);
    int c = lower_bound(all(comy), x) - comy.begin();
    used[c] = 1;
    rep(i, m) {
        int a = lower_bound(all(comy), l[i]) - comy.begin();
        int b = lower_bound(all(comy), r[i]) - comy.begin();
        //cerr << a << " " << b << endl;
        for(int j = a; j < b; ++ j) {
            //cerr << j << " " << used[j] << endl;
            if(used[j]) {
                for(int k = a; k < b; ++ k) {
                    used[k] = 1;
                }
                break;
            }
        }
    }
    int ans = 0;
    rep(i, sz - 1) {
        //cerr << used[i] << endl;
        if(used[i]) {
            ans += comy[i + 1] - comy[i];
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	int t; cin >> t; rep(i, t)solve();
	//solve();
    return 0;
}