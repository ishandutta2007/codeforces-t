//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(0);cin.tie(0)
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
const int LIM=2e5+5,MOD=1e9+7;
const ld EPS = 1e-9;

int read(){
    int xx=0,ff=1;char ch=getchar();
    while(ch>'9'||ch<'0'){if(ch=='-')ff=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){xx=(xx<<3)+(xx<<1)+ch-'0';ch=getchar();}
    return xx*ff;
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

bool check(char a, char b, char c, char d){
	if(a!=d) return 0;
	if(b!=c) return 0;
	if(a==b) return 0;
	return 1;
}

signed main(){
	fastio;
	int tests = 1;
	cin>>tests;
	
	while(tests--){

		int a[4];
		forn(i,4) cin >> a[i];

		string s;
		cin >> s;

		bool p = 1;
		int n = s.length();

		int num_a = a[0] + a[2] + a[3];
		int num_b = a[1] + a[2] + a[3];

		vp32 ord;
		char last='Z';
		int curr = 0;

		forn(i,s.length()){
			if(s[i] == 'A'){
				num_a--;
			}
			else{
				num_b--;
			}
			if(s[i]==last){
				if(curr/2>0){
					if(curr%2==1) ord.pb({MOD*curr/2, 4});
					else if(last=='A') ord.pb({curr/2, 3});
					else ord.pb({curr/2, 2});
				}
				curr=1;
			}
			else{
				curr+=1;
			}
			last = s[i];
		}

		if(curr/2>0){
			if(curr%2==1) ord.pb({MOD*curr/2, 4});
			else if(last=='A') ord.pb({curr/2, 3});
			else ord.pb({curr/2, 2});
		}

		sort(all(ord));
		// cout << ord << ln;
		forstl(r, ord){
			int len = r.fi, type = r.se;

			if(type==4){
				len /= MOD;
				int z = min(a[2], len);
				a[2] -= z;
				len -= z;
				z = min(a[3], len);
				a[3] -= z;
				len -= z;
				continue;
			}

			if(a[type] >= len){
				a[type] -= len;
				continue;
			}
			len -= a[type];
			a[type] = 0;
			a[5-type] -= min(len-1, a[5-type]);
		}

		if(num_a != 0) p = 0;
		if(num_b != 0) p = 0;

		if(a[2]!=0) p = 0;
		if(a[3]!=0) p = 0;

		if(p){
			cout << "YES" << ln;
		}
		else{
			cout << "NO" << ln;
		}

	}

	return 0;
}