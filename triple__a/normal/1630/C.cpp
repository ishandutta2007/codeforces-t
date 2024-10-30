// #pragma comment(linker, "/STACK:102400000,102400000")
#pragma GCC optimize("O3")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
// #pragma GCC optimize("trapv")
#include<bits/stdc++.h>
 
#define int long long
#define double long double
using namespace std;
 
namespace std {
 
template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
 
	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};
 
template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}
 
} // namespace std
 
#define rep(i,n) for (int i=0;i<(int)(n);++i)
#define rep1(i,n) for (int i=1;i<=(int)(n);++i)
#define range(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
 
typedef long long ll;
typedef unsigned long long ull;
// typedef long double ld;
typedef pair<int, int> pii;
typedef vector<int> vi;
 
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
const int mod=1e9+7;
const int INF=LLONG_MAX/4;
const double EPS=1e-9;
const int N=300007;
const int K=407;
int n,k;
int a[N];
int L[N],R[N],nxt[N];
signed main(){
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cout.precision(15);
    cin>>n;
    rep(i,n) cin>>a[i];
    rep1(i,n) L[i]=R[i]=-1,nxt[i]=-1;
    rep(i,n) {
        if (L[a[i]]==-1) L[a[i]]=i;
        R[a[i]]=i;
    }
    vector<pii> seg;
    rep1(i,n){
        if (L[i]==-1) continue;
        nxt[L[i]]=R[i];
    }
    int cur=-1, mx=-1, ans=0;
    while (cur<n-1){
        while (cur<n-1&&cur==mx){ans++, cur++, mx=nxt[cur];}
        if (cur==n-1) break;
        int now=mx;
        for(;cur<mx;cur++) now=max(now,nxt[cur]);
        mx=max(mx,now), ans++;
    }
    cout<<n-ans;
    return 0;
}