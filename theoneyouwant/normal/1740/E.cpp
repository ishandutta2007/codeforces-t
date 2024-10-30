//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int p[LIM];
int num[LIM];
int child[LIM];
v32 comp[LIM];
int ans[LIM][2];
int h[LIM];
v32 cc[LIM];
bool isfp[LIM];

int ch(int node){
	if(h[node]>0) return h[node];
	int hmx = 0;
	forstl(r, cc[node]){
		hmx = max(hmx, ch(r));
	}
	hmx++;
	return (h[node]=hmx);
}

int fans(int node, int val){
	if(ans[node][val]!=-1) return ans[node][val];
	if(val == 0){
		return 0;
	}
	else{
		int s = 0;
		forstl(r, cc[node]){
			s += fans(r, 1);
		}
		s = max(s, ch(node));
		return (ans[node][val]=s);
	}
}


int main(){
	fastio;


	int n;
	cin >> n;

	p[1]=1;
	forsn(i, 2, n+1){
		cin >> p[i];
		cc[p[i]].pb(i);
		child[p[i]]++;
	}

	forsn(i,1,n+1){
		forn(j,2){
			ans[i][j] = -1;
		}
	}

	// int ans = 0;

	int ans = fans(1, 1);
	// forstl(r, cc[1]){
	// 	ans += ch(r);
	// }
	// if(cc[1].size()<2) ans += 1;
	
	cout << ans << ln;


	return 0;
}