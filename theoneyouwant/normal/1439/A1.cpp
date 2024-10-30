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

int main(){
	fastio;
	int tests = 1;
	cin>>tests;
	
	while(tests--){

		int n, m;
		cin>>n>>m;
		int a[n][m];
		forn(i,n){
			forn(j,m){
				char x; cin>>x;
				if(x == '0') a[i][j] = 0;
				else a[i][j] = 1;
			}
		}

		vector<vp32> op;

		int dx[] = {1, 0, 0, 1};
		int dy[] = {0, 1, 0, 1};

		forn(i,n){
			forn(j,m){
				bool np = 0;
				int num = 0;
				vp32 pres;
				vp32 oth;
				forn(k,4){	
					if(i + dx[k] >= n) np = 1;
					else if(j + dy[k] >= m) np = 1;
					else if(a[i+dx[k]][j+dy[k]] == 1){
						num++;
						pres.pb(mp(i+dx[k], j+dy[k]));
					} 
					else{
						oth.pb(mp(i+dx[k], j+dy[k]));
					}
				}
				if(np || pres.size() == 0) continue;
				forn(k,4){
					a[i+dx[k]][j+dy[k]] = 0;
				}
				if(pres.size() == 4){
					vp32 p1, p2, p3, p4;
					p1.pb(pres[0]); p1.pb(pres[1]); p1.pb(pres[2]);
					p2.pb(pres[0]); p2.pb(pres[1]); p2.pb(pres[3]);
					p3.pb(pres[0]); p3.pb(pres[2]); p3.pb(pres[3]);
					p4.pb(pres[1]); p4.pb(pres[2]); p4.pb(pres[3]);
					op.pb(p1); op.pb(p2);
					op.pb(p3); op.pb(p4);
					continue;
				}
				if(pres.size() == 3){
					op.pb(pres);
					continue;
				}
				if(pres.size() == 2){
					vp32 p1, p2;
					p1.pb(pres[0]); p1.pb(oth[0]); p1.pb(oth[1]);
					op.pb(p1);
					p2.pb(pres[1]); p2.pb(oth[0]); p2.pb(oth[1]);
					op.pb(p2);
					continue;
				}
				if(pres.size() == 1){
					vp32 p1, p2, p3;
					p1.pb(pres[0]); p1.pb(oth[0]); p1.pb(oth[1]);
					p2.pb(pres[0]); p2.pb(oth[2]); p2.pb(oth[0]);
					p3.pb(pres[0]); p3.pb(oth[1]); p3.pb(oth[2]);
					op.pb(p1);
					op.pb(p2);
					op.pb(p3);
					continue; 
				}
			}
		}

		cout<<op.size()<<ln;
		forstl(r,op){
			forstl(k,r){
				cout<<k.fi+1<<" "<<k.se+1<<" ";
			}
			cout<<ln;
		}

	}

	return 0;
}