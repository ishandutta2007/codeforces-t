// --------------------------------------------------<TEMPLATE>--------------------------------------------------
// --------------------<optimizations>--------------------
#pragma GCC optimize("O3")
//(UNCOMMENT WHEN HAVING LOTS OF RECURSIONS)\
#pragma comment(linker, "/stack:200000000")
//(UNCOMMENT WHEN TRYING TO BRUTEFORCE WITH A LOT OF LOOPS)\
#pragma GCC optimize("unroll-loops")

// -------------------</optimizations>--------------------

// ---------------<Headers and namespaces>----------------
#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;

// ---------------</Headers and namespaces>---------------

// -----------------<Defines and typedefs>----------------
typedef tree<int,null_type,less<int>,rb_tree_tag,
tree_order_statistics_node_update> indexed_set;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the iterator to kth largest element.(0-based)

typedef long long ll;
typedef long double LD;
#define int ll
#define double LD
#define pb push_back
#define mp make_pair
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
typedef map<int,int> mii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
#define F first
#define S second
#define PQ(type) priority_queue<type>
#define PQD(type) priority_queue<type,vector<type>,greater<type> >
#define ITR :: iterator it
#define WL(t) while(t --)
#define SZ(x) ((int)(x).size())
#define runtime() ((double)clock() / CLOCKS_PER_SEC)
#define TR(container,it) for(typeof(container.begin()) it=container.begin();it!=container.end();it++)
#define sqr(x) ((x)*(x))

// -----<SCANF>-----
#define sfi(x) scanf("%d",&x);
#define sfi2(x,y) scanf("%d%d",&x,&y);
#define sfi3(x,y,z) scanf("%d%d%d",&x,&y,&z);

#define sfl(x) scanf("%lld",&x);
#define sfl2(x,y) scanf("%lld%lld",&x,&y);
#define sfl3(x,y,z) scanf("%lld%lld%lld",&x,&y,&z);

#define sfs(x) scanf("%s",x);
#define sfs2(x,y) scanf("%s%s",x,y);
#define sfs3(x,y,z) scanf("%s%s%s",x,y,z);
// ----</SCANF>-----

// ----<PRINTF>-----
#define pfi(x) printf("%d\n",x);
#define pfi2(x,y) printf("%d %d\n",x,y);
#define pfi3(x,y,z) printf("%d %d %d\n",x,y,z);

#define pfl(x) printf("%lld\n",x);
#define pfl2(x,y) printf("%lld %lld\n",x,y);
#define pfl3(x,y,z) printf("%lld %lld %lld\n",x,y,z);

#define pfs(x) printf("%s\n",x);
#define pfs2(x,y) printf("%s %s\n",x,y);
#define pfs3(x,y,z) printf("%s %s %s\n",x,y,z);
// ----</PRINTF>----

#define FLSH fflush(stdout)
#define fileIO(name) \
    freopen(name".in", "r", stdin); \
    freopen(name".out", "w", stdout);
#define PRECISION(x) cout << fixed << setprecision(x); 
#define FAST_IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

// ----------------</Defines and typedefs>----------------

// -------------------<Debugging stuff>-------------------
#define TRACE

#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
	const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...)
#endif

// ------------------</Debugging stuff>-------------------

// ------------------------<Consts>-----------------------
const int MAXN = 1000005;
const int SQRTN = 1003;
const int LOGN = 22;
const double PI=acos(-1);
const int INF = 1000000000;
const int MOD = 1000000007;
const int FMOD = 998244353;
const double eps = 1e-9;

// -----------------------</Consts>-----------------------

// -------------------------<RNG>-------------------------
mt19937 RNG(chrono::steady_clock::now().time_since_epoch().count()); 
#define SHUF(v) shuffle(all(v), RNG);
// Use mt19937_64 for 64 bit random numbers.

// ------------------------</RNG>-------------------------

// -----------------<Modular Arithmetic>------------------
template<typename T> T gcd(T a, T b){return(b?__gcd(a,b):a);}
template<typename T> T lcm(T a, T b){return(a*(b/gcd(a,b)));}
int add(int a, int b, int c){int res=a+b;return(res>=c?res-c:res);}
int mod_neg(int a, int b, int c){int res;if(abs(a-b)<c)res=a-b;else res=(a-b)%c;return(res<0?res+c:res);}
int mul(int a, int b, int c){ll res=(ll)a*b;return(res>=c?res%c:res);}
ll mulmod(ll a,ll b, ll m){ll q = (ll)(((LD)a*(LD)b)/(LD)m);ll r=a*b-q*m;if(r>m)r%=m;if(r<0)r+=m;return r;}
template<typename T>T expo(T e, T n){T x=1,p=e;while(n){if(n&1)x=x*p;p=p*p;n>>=1;}return x;}
template<typename T>T power(T e, T n, T m){T x=1,p=e;while(n){if(n&1)x=mul(x,p,m);p=mul(p,p,m);n>>=1;}return x;}
template<typename T>T extended_euclid(T a, T b, T &x, T &y){T xx=0,yy=1;y=0;x=1;while(b){T q=a/b,t=b;b=a%b;a=t;\
t=xx;xx=x-q*xx;x=t;t=yy;yy=y-q*yy;y=t;}return a;}
template<typename T>T mod_inverse(T a, T n){T x,y,z=0;T d=extended_euclid(a,n,x,y);return(d>1?-1:mod_neg(x,z,n));}

// -----------------</Modular Arithmetic>-----------------
// --------------------------------------------------</TEMPLATE>--------------------------------------------------

void solvethetestcase();

signed main(){
	// (UNCOMMENT FOR CIN/COUT) \
	FAST_IO
	PRECISION(10)

	int t = 1;
	// (UNCOMMENT FOR MULTIPLE TEST CASES) \
	sfl(t);
	FOR(testcase,1,t+1){
		// (UNCOMMENT FOR CODEJAM) \
		printf("Case #%lld: ",testcase); 
		solvethetestcase();
	}
}

int n;
int a[200005];
int res[200005];

const int MAX = 2e5 + 5;
const int LIM = 8e5 + 5;        //equals 2 * 2^ceil(log2(n))

pii seg[LIM];
int lazy[LIM];
bool push[LIM];

//Complexity: O(1)
//Stores what info. segment[i..j] should store
pii combine(pii x, pii y) {
	if(x < y) return x;
	return y;
}

//Lazy propagation
void propagate(int t, int i, int j) {
	if (push[t]) {
		seg[t].F = seg[t].F + lazy[t];
		if (i != j) {
			push[t*2] = true;
			push[t*2 + 1] = true;
			lazy[t*2] = lazy[t*2] + lazy[t];
			lazy[t*2 + 1] = lazy[t*2 + 1] + lazy[t];
		}
		push[t] = false;
		lazy[t] = 0;
	}
}

//Complexity: O(n)
void build(int t, int i, int j) {
	push[t] = false;
	lazy[t] = 0;
	if (i == j) {
		//base case : leaf node information to be stored here
		seg[t] = {a[i],-i};
		return ;
	}
	int mid = (i + j) / 2;
	build(t*2, i, mid);
	build(t*2 + 1, mid + 1, j);
	seg[t] = combine(seg[2*t], seg[2*t+1]);
}

//Complexity: O(log n)
void update(int t, int i, int j, int l, int r, int x) {
	propagate(t, i, j);
	if (i > r || j < l) {
		return ;
	}
	if (l <= i && j <= r) {
		//base case : leaf node information to be stored here
		lazy[t] += x;
		push[t] = true;
		propagate(t, i, j);
		return ;
	}
	int mid = (i + j) / 2;
	update(t*2, i, mid, l, r, x);
	update(t*2 + 1, mid + 1, j, l, r, x);
	seg[t] = combine(seg[2*t], seg[2*t+1]);
}

//Complexity: O(log n)
pii query(int t, int i, int j, int l, int r) {
	propagate(t, i, j);
	if (i > r || j < l) {
		return {1,1};
	}
	if (l <= i && j <= r) {
		return seg[t];
	}
	int mid = (i + j) / 2;
	if (l <= mid) {
		if (r <= mid) {
			return query(t*2, i, mid, l, r);
		}
		else {
			pii x = query(t*2, i, mid, l, r);
			pii y = query(t*2 + 1,  mid + 1, j, l, r);
			return combine(x,y);
		}
	}
	else {
		return query(t*2 + 1,  mid + 1, j, l, r);
	}
}

void solvethetestcase(){
	sfl(n)
	REP(i,n) sfl(a[i])
	build(1,0,n-1);
	REP(i,n){
		int pos = -seg[1].S;
		res[pos] = i+1;
		if(pos != n-1) update(1,0,n-1,pos+1,n-1,-(i+1));
		update(1,0,n-1,pos,pos,(n*n+10));
		// trace(pos,i+1);
		// REP(i,n){
			// trace(i,query(1,0,n-1,i,i).F);
		// }
	}
	REP(i,n) printf("%lld ",res[i]);
	printf("\n");
}