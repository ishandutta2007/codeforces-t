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
template<typename T>
map<T,ll> compress(vector<T> &v){
  sort(ALL(v));
  v.erase(unique(ALL(v)),v.end());
  map<T, ll> ret;
  for(ll i=0;i<(ll)v.size();i++)
    ret[v[i]]=i;
  return ret;
}
template< typename flow_t >
struct Dinic {
  const flow_t INF;

  struct edge {
    ll to;
    flow_t cap;
    ll rev;
    bool isrev;
  };

  vector< vector< edge > > graph;
  vector< ll > min_cost, iter;

  Dinic(ll V) : INF(numeric_limits< flow_t >::max()), graph(V) {}

  void add_edge(ll from, ll to, flow_t cap) {
    graph[from].emplace_back((edge) {to, cap, (ll) graph[to].size(), false});
    graph[to].emplace_back((edge) {from, 0, (ll) graph[from].size() - 1, true});
  }

  bool bfs(ll s, ll t) {
    min_cost.assign(graph.size(), -1);
    queue< ll > que;
    min_cost[s] = 0;
    que.push(s);
    while(!que.empty() && min_cost[t] == -1) {
      ll p = que.front();
      que.pop();
      for(auto &e : graph[p]) {
        if(e.cap > 0 && min_cost[e.to] == -1) {
          min_cost[e.to] = min_cost[p] + 1;
          que.push(e.to);
        }
      }
    }
    return min_cost[t] != -1;
  }

  flow_t dfs(ll idx, const ll t, flow_t flow) {
    if(idx == t) return flow;
    for(ll &i = iter[idx]; i < graph[idx].size(); i++) {
      edge &e = graph[idx][i];
      if(e.cap > 0 && min_cost[idx] < min_cost[e.to]) {
        flow_t d = dfs(e.to, t, min(flow, e.cap));
        if(d > 0) {
          e.cap -= d;
          graph[e.to][e.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }

  flow_t max_flow(ll s, ll t) {
    flow_t flow = 0;
    while(bfs(s, t)) {
      iter.assign(graph.size(), 0);
      flow_t f = 0;
      while((f = dfs(s, t, INF)) > 0) flow += f;
    }
    return flow;
  }

  void output() {
    for(ll i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        cout << i << "->" << e.to << " (flow: " << rev_e.cap << "/" << e.cap + rev_e.cap << ")" << endl;
      }
    }
  }
  //<(from->to),flow>
  using R=vector<pair<pair<ll,ll>,flow_t>>;
  R restore() {
    R ret;
    for(ll i = 0; i < graph.size(); i++) {
      for(auto &e : graph[i]) {
        if(e.isrev) continue;
        auto &rev_e = graph[e.to][e.rev];
        ret.emplace_back(make_pair(i,e.to),rev_e.cap);
      }
    }
    return ret;
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll k,n;cin>>k>>n;
  if(n==0){
    cout<<0<<endl;
    return 0;
  }
  vector<ll>x1(n),y1(n),x2(n),y2(n);
  rep(i,0,n)cin>>x1[i]>>y1[i]>>x2[i]>>y2[i];
  vector<ll>v;
  rep(i,0,n){
    y2[i]++;x2[i]++;
    v.PB(x1[i]);
    v.PB(x2[i]);
    v.PB(y1[i]);
    v.PB(y2[i]);
  }
  auto mp=compress(v);
  ll sz=mp.size();
  vector<string>s(sz,string(sz,'.'));
  rep(i,0,n){
    //cout<<mx[x1[i]] spa mx[x2[i]] spa my[y1[i]] spa my[y2[i]]<<endl;
    rep(x,mp[x1[i]],mp[x2[i]])rep(y,mp[y1[i]],mp[y2[i]]){
      s[x][y]='#';
    }
  }
  sz--;
  Dinic<ll>dinic(2*sz+2);
  ll S=2*sz;
  ll T=S+1;
  rep(i,0,sz){
    dinic.add_edge(S,i,v[i+1]-v[i]);
    dinic.add_edge(i,T,0);
  }
  rep(i,0,sz){
    dinic.add_edge(sz+i,T,v[i+1]-v[i]);
    dinic.add_edge(S,sz+i,0);
  }
  rep(i,0,sz)rep(j,0,sz){
    if(s[i][j]=='#'){

      dinic.add_edge(i,sz+j,1e14);
    }
  }
  cout<<dinic.max_flow(S,T)<<endl;
  return 0;
}