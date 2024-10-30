//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define fi first
#define se second
#define MP make_pair
#define MT make_tuple
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = (n); i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = (ll)(m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++){for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<ll>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<ll>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
vector<ll> bfs(vector<vector<ll>>&g,ll k=0){
  vector<ll>dist(g.size(),INF);
  queue<P> q;
  ll n=g.size();
  q.emplace(k,0);
  while(!q.empty()){
    ll x=q.front().fi;
    ll len=q.front().se;
    if(dist[x]==INF){
      dist[x]=len;
      for(ll i=0;i<g[x].size();i++){
        q.emplace(g[x][i],len+1);
      }
    }
    q.pop();
  }
  return dist;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    ll n,m;cin>>n>>m;
    vector<vector<ll>>g(n);
    rep(i,0,m){
      ll u,v;cin>>u>>v;u--;v--;
      g[u].PB(v);
    }
    auto dc=bfs(g,0);
    vector<vector<ll>>gr(2*n);
    rep(i,0,n){
      for(auto to:g[i]){
        if(dc[i]<dc[to]){
          gr[to].PB(i);
          gr[to+n].PB(i+n);
        }
        else{
          gr[to].PB(i+n);
        }
      }
    }
    vector<ll>ord(n);
    iota(ALL(ord),0);
    sort(ALL(ord),[&](ll i,ll j){return dc[i]<dc[j];});
    vector<ll>dr(2*n,INF);
    for(auto i:ord){
      if(dr[i]!=INF)continue;
      queue<ll>que;
      que.push(i);
      dr[i]=dc[i];
      while(!que.empty()){
        auto p=que.front();
        que.pop();
        for(auto to:gr[p]){
          if(dr[to]!=INF)continue;
          que.push(to);
          dr[to]=dr[p];
        }
      }
    }
    vector<ll>ret(n);
    rep(i,0,n)ret[i]=min(dr[i],dr[i+n]);
    debug(ret,n);
  }
  return 0;
}