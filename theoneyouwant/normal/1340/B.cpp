//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

pair<int,bool> change(string s, string s2){
	// cout<<"OK"<<endl;
	int ch = 0;
	bool p = 1;
	forn(i,s.length()){
		if(s[i] == '1' && s2[i] == '0'){
			p = 0;
			break;
		}
		if(s[i] == '0' && s2[i] == '1') ch++;
	}
	return mp(ch,p);
}

string get(int a){
	// cout<<"OK"<<endl;
	string g[] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	// cout<<g[9]<<endl;
	return g[a];
}

int main(){
	fastio;

	ll n,k; cin>>n>>k;
	bool dp[n+1][k+20];
	forn(i,n+1){
		forn(j,k+20) dp[i][j] = 0;
	}
	dp[0][0] = 1;
	string num[n];
	forn(i,n){
		cin>>num[i];
	}
	string act[n];
	forn(i,n) act[i] = num[i];
	forn(i,n) num[i] = act[n-1-i];

	forn(i,n){
		v32 ch;
		forn(l,10){
			p32 g = change(num[i],get(l));
			if(g.se) ch.pb(g.fi);
		}
		forn(j,k+1){
			if(dp[i][j] == 0) continue;		
			forstl(r,ch) dp[i+1][j+r] = 1;
		}
	}

	if(dp[n][k] == 0){
		cout<<-1<<ln;
		return 0;
	}

	forn(i,n) num[i] = act[i];

	v32 ans;
	forn(i,n){
		int mxtak = 0;
		forn(l,10){
			p32 g = change(num[i],get(l));
			if(g.se && k >= g.fi){
				if(dp[n-1-i][k-g.fi] == 1) mxtak = l;
			}
		}
		k -= change(num[i],get(mxtak)).fi;
		ans.pb(mxtak);
	}
	forstl(r,ans) cout<<r;
	cout<<ln;

	return 0;
}