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

//#define int long long
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

bool used[200200];

void solve() {
	int n; cin >> n;
    vector<int> a(n);
    rep(i, 200200) used[i] = 0;
    rep(i, n) {
        cin >> a[i];
        if(i >= 1) {
            if(a[i] < a[i - 1]) {
                cout << -1 << endl;
                return;
            }
        }
        used[a[i]] = 1;
    }
    vector<int> b(n);
    set<int> se;
    for(int i = 0; i <= 200200; ++ i) {
        se.insert(i);
    }
    int cur = 0;
    rep(i, n) {
        if(i == 0 || a[i - 1] == a[i]) {
            if(i == 0 && a[i] == 1) {
                b[i] = 0;
                se.erase(0);
                cur = 1;
                continue;
            }
            if(i == 0 && a[i] >= 2) {
                cout << -1 << endl;
                return;
            }
            for(int j = cur;; ++ j) {
                if(!used[j]) {
                    b[i] = j;
                    se.erase(j);
                    cur = j + 1;
                    break;
                }
            }
        } else {
            auto ite = se.lower_bound(a[i]);
            if(ite == se.begin()) {
                b[i] = 0;
                continue;
            }
            -- ite;
            if(ite != se.begin()) {
                cout << -1 << endl;
                return;
            }
            b[i] = *ite;
            se.erase(b[i]);
        }
    }
    rep(i, n) {
        if(i) cout << " ";
        cout << b[i];
    }
    cout << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}