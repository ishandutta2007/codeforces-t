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

int n, m;
vector<vector<int>> g;

struct UnionFind {
    vector<int> par, w;
    vector<int> ma, mi;
    
    UnionFind(int n) { init(n); }
    void init(int n) { 
        par.assign(n, -1); w.assign(n, 0);
        ma.resize(n); mi.resize(n);
        iota(all(ma), 0);
        iota(all(mi), 0);
    }
    
    int root(int x) {
        if (par[x] < 0) return x;
        else return par[x] = root(par[x]);
    }
    
    bool issame(int x, int y) {
        return root(x) == root(y);
    }
    
    bool merge(int x, int y) {
        x = root(x); y = root(y);
        if (x == y) {
            ++w[x];
            return false;
        }
        if (par[x] > par[y]) swap(x, y); // merge technique
        par[x] += par[y];
        par[y] = x;
        w[x] += w[y];
        chmax(ma[x], ma[y]);
        chmin(mi[x], mi[y]);
        ++w[x];
        return true;
    }
    
    int size(int x) {
        return -par[root(x)];
    }
 
    int wei(int x) {
        return w[root(x)];
    }

    int maxi(int x) {
        return ma[root(x)];
    }

    int mini(int x) {
        return mi[root(x)];
    }
};

void solve() {
	cin >> n >> m;
    g.assign(n, vector<int>());
    UnionFind uf(n);
    rep(i, m) {
        int u, v; cin >> u >> v; --u, --v;
        g[u].pb(v);
        g[v].pb(u);
        uf.merge(u, v);
    }
    int r = -1;
    int ans = 0;
    rep(i, n) {
        if(uf.root(i) != r) {
            if(r == -1) {
                r = uf.root(i);
            } else {
                ans ++;
                uf.merge(i, r);
                r = uf.root(i);
            }
        }
        if(uf.maxi(i) == i) {
            r = -1;
        }
    }
    cout << ans << endl;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(10);
	//int t; cin >> t; rep(i, t)solve();
	solve();
    return 0;
}