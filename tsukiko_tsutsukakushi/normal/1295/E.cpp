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

template<typename T, typename S>
struct LazySegmentTree{
private:
    int n;
    vector<T> node;
    vector<S> lazy;
    T E0;
    S E1;

    inline void updatef(S& lazy,S& value){
        lazy += value;
        //lazy = max(lazy, value);
        //lazy = min(lazy, value);
    }
    inline void calculatef(T& node,S& lazy,int len){
        //node += lazy * len; //sum
        node += lazy ; //max
    }
    inline T queryf(T& x,T& y){
        return min(x, y);
        //return x + y;
        //return x * y;
        //return max(x, y);
    }
public:
    LazySegmentTree(int sz,T nodeE,S lazyE ):E0(nodeE), E1(lazyE){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
    }

    LazySegmentTree(vector<T>& v,T E0,S E1 ):E0(E0),E1(E1){
        n=1;
        int sz=v.size();
        while(n<sz)n<<=1;
        node.resize(2*n-1,E0);
        lazy.resize(2*n-1,E1);
        rep(i,sz)node[i+n-1] = v[i];
        for(int i=n-2; i>=0; --i){
            node[i] = queryf(node[2*i+1],node[2*i+2]);
        }
    }

    void eval(int k,int l,int r){
        if(lazy[k]==E1)return ;
        calculatef(node[k], lazy[k], r-l);
        if(r-l>1){
            updatef(lazy[2*k+1], lazy[k]);
            updatef(lazy[2*k+2], lazy[k]);
        }
        lazy[k]=E1;
    }

    void update(int a, int b, S x,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return;
        if(a<=l&&r<=b){
            updatef(lazy[k], x);
            eval(k,l,r);
        }
        else {
            update(a,b,x,2*k+1,l,(l+r)/2);
            update(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }

    T query(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        eval(k,l,r);
        if(r<=a||b<=l)return E0;
        if(a<=l&&r<=b)return node[k];
        T xl=query(a,b,2*k+1,l,(l+r)/2);
        T xr=query(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
};

void solve() {
	int n; cin >> n;
    vector<int> p(n), a(n);
    rep(i, n) {
        cin >> p[i];
        --p[i];
    }
    rep(i, n) {
        cin >> a[i];
    }
    vector<int> s(n + 1, 0);
    LazySegmentTree<int, int> seg(s, INF, 0);
    rep(i, n) {
        if(i == 0) {
            seg.update(0, p[i] + 1, a[i]);
        } else {
            seg.update(p[i] + 1, n + 1, a[i]);
        }
    }
    int ans = seg.query(0, n + 1);
    for(int i = 1; i < n - 1; ++i) {
        seg.update(0, p[i] + 1, a[i]);
        seg.update(p[i] + 1, n + 1, -a[i]);
        chmin(ans, seg.query(0, n + 1));
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