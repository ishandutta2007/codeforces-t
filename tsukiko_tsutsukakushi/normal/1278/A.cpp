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
//#define int long long

void solve() {
	string p, s; cin >> p >> s;
    int pcnt[26];
    int n = (int)p.size();
    rep(i, 26) {
        pcnt[i] = 0;
    }
    rep(i, n) {
        pcnt[(p[i] - 'a')] ++;
    }
    int m = (int)s.size();
    if(m < n) {
        cout << "NO" << endl;
        return;
    }
    int scnt[110][26];
    rep(i, 110) {
        rep(j, 26) {
            scnt[i][j] = 0;
        }
    }
    rep(i, m) {
        rep(j, 26) {
            scnt[i + 1][j] = scnt[i][j];
        }
        scnt[i + 1][(s[i] - 'a')] ++;
    }
    for(int i = n; i <= m; ++i) {
        int cnt[26];
        rep(j, 26) {
            cnt[j] = scnt[i][j] - scnt[i - n][j];
        }
        bool flag = 1;
        rep(j, 26) {
            if(cnt[j] != pcnt[j]) flag= 0;
        }
        if(flag) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//init();
	int t; cin >> t; rep(i, t)solve();
	//solve();
	//cout << "finish" << endl;
    return 0;
}