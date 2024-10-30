//By TheOneYouWant
#pragma GCC optimize ("-O2")
#include <bits/stdc++.h>
using namespace std;
#define fastio ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define memreset(a) memset(a,0,sizeof(a))
#define testcase(t) int t;cin>>t;while(t--)
#define forstl(i,v) for(auto &i: v)
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define leadzero(a) __builtin_clz(a) // count leading zeroes
#define trailzero(a) __builtin_ctz(a) // count trailing zeroes
#define bitcount(a) __builtin_popcount(a) // count set bits (add ll)
#define ln endl
#define dbg(x) cerr<<#x<<" = "<<x<<endl
#define dbg2(x,y) cerr<<#x<<" = "<<x<<" & "<<#y<<" = "<<y<<endl;
#define dbgstl32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it<<ln;} cerr<<endl
#define dbgstlp32(v) cerr<<#v<<" = \n"; { int c=0; forstl(it,v) \
cerr<<"    Term "<< ++c <<" = "<<it.fi<<" , "<<it.se<<ln;} cerr<<endl
#define dbgarr(v,s,e) cerr<<#v<<" = "; forsn(i,s,e) cerr<<v[i]<<", "; cerr<<endl
#define inp freopen("input.txt", "r", stdin)
#define outp freopen("output.txt", "w", stdout)
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
typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;
typedef pair<ll,ll> p64;
typedef pair<int,int> p32;
typedef pair<int,p32> p96;
typedef vector<ll> v64;
typedef vector<int> v32; 
typedef vector<v32> vv32;
typedef vector<v64> vv64;
typedef vector<p32> vp32;
typedef vector<vp32> vvp32;
typedef map<int,int> m32;
const ll MOD = 1e9+7, LIM = 3e5+5;
const ld EPS = 1e-9;
int n;
v32 adj[LIM];
int child[LIM][2];
int parent[LIM][2];
bool visited[LIM];
int a[LIM];


void firstbfs(int t){
	int ans[2] = {0};
	forstl(r,adj[t]){
		if(visited[r]) continue;
		visited[r]=1;
		firstbfs(r);
		ans[0]+=child[r][0];
		ans[1]+=child[r][1];
		}
	if(a[t]==1) ans[0]++;
	else if(a[t]==2) ans[1]++;
	child[t][0] = ans[0];
	child[t][1] = ans[1];
}

int main(){
	fastio;
	cin>>n;
	forn(i,n) cin>>a[i];
	forn(i,n-1){
		int u,v;
		cin>>u>>v;
		u--;
		v--;
		adj[u].pb(v);
		adj[v].pb(u);
	}
	forn(i,n){
		forn(j,2){
			child[i][j]=0;
		}
	}
	forn(i,n) visited[i]=0;
	visited[0]=1;
	firstbfs(0);
	// forn(i,n){
	// 	forn(j,2){
	// 		cout<<i+1<<" "<<j<<" "<<child[i][j]<<ln;
	// 	}
	// }
	forn(i,n) visited[i]=0;
	int answer=0;
	queue<int> q;
	q.push(0);
	while(!q.empty()){
		int t = q.front();
		q.pop();
		forstl(r,adj[t]){
			if(visited[r]) continue;
			visited[r]=1;
			q.push(r);
			if((child[r][0]==0 ||child[r][1]==0) && (child[0][1]==child[r][1] || child[0][0]==child[r][0]) ){
				//cout<<t+1<<" "<<r+1<<ln;
				answer++;
			}
		}
	}
	cout<<answer<<ln;
	return 0;
}