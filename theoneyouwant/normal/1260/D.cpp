//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define int long long int
#define all(x) x.begin(),x.end()
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i=0;i<e;++i)
#define forsn(i,s,e) for(int i=s;i<e;++i)
#define rforn(i,s) for(int i=s;i>=0;--i)
#define rforsn(i,s,e) for(int i=s;i>=e;--i)
#define bitcount(a) __builtin_popcount(a) // set bits (add ll)
#define ln '\n'
#define getcurrtime() cerr<<"Time = "<<((double)clock()/CLOCKS_PER_SEC)<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inputfile freopen("input.txt", "r", stdin)
#define outputfile freopen("output.txt", "w", stdout)
#define dbg(args...) { string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); \
stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
void err(istream_iterator<string> it) { cerr<<endl; }
template<typename T, typename... Args>
void err(istream_iterator<string> it, T a, Args... args) {
	cerr << *it << " = " << a << "\t"; err(++it, args...);
}
template<typename T1,typename T2>
ostream& operator <<(ostream& c,pair<T1,T2> &v){
	c<<"("<<v.fi<<","<<v.se<<")"; return c;
}
template <template <class...> class TT, class ...T>
ostream& operator<<(ostream& out,TT<T...>& c){
    out<<"{ ";
    forstl(x,c) out<<x<<" ";
    out<<"}"; return out;
}
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<p64> vp64;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const int LIM=1e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

ll m,n,k,t;
vector<pair<int,p64> > trap;
v32 soldiers;

bool check(int num){

	if(num>m) return 0;

	if(num == 0){
		return 1;
	}

	ll time = n+1;

	int cap = soldiers[num-1];
	vp64 con;
	forstl(r,trap){
		if(r.fi<=cap) break;
		con.pb(r.se);
	}
	sort(con.begin(),con.end());
	int went = -1;
	forstl(r,con){
		went = max(went,r.fi-1);
		if(r.se <= went) continue;
		time += 2*(r.se-went);
		went = r.se;
	}
	// cout<<num<<" "<<time<<ln;

	if(time <= t) return 1;
	return 0;
}

signed main(){
	fastio;

	cin>>m>>n>>k>>t;
	
	forn(i,m){
		int x;
		cin>>x;
		soldiers.pb(x);
	}
	sort(soldiers.begin(),soldiers.end(),greater<int>());

	forn(i,k){
		ll l,r,d;
		cin>>l>>r>>d;
		trap.pb(mp(d,mp(l,r)));
	}
	sort(trap.begin(),trap.end(),greater<pair<int,p32>>());

	int l = 0, r = m, mid;
	while(true){
		mid = (l+r)/2;
		if(l >= r) break;
		bool ok = check(mid);
		bool ok2 = check(mid+1);
		if(ok == 1 && ok2 == 0) break;
		if(ok == 1 && ok2 == 1) l = mid+1;
		else r = mid-1;
	}

	cout<<mid<<ln;

	return 0;
}