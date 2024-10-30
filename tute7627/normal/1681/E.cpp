//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define lfs cout<<fixed<<setprecision(10)
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define UNIQUE(a) (a).erase(unique((a).begin(),(a).end()),(a).end())
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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T1,typename T2,typename T3>void anss(T1 x,T2 y,T3 z){ans(x!=y,x,z);};  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
template<typename T>void debug(const vector<T>&v){debug(v,v.size());}
template<typename T>void debug(const vector<vector<T>>&v){for(auto &vv:v)debug(vv,vv.size());}
template<typename T>void debug(stack<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(queue<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(deque<T> st){while(!st.empty()){cout<<st.front()<<" ";st.pop_front();}cout<<endl;}
template<typename T>void debug(PQ<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(QP<T> st){while(!st.empty()){cout<<st.top()<<" ";st.pop();}cout<<endl;}
template<typename T>void debug(const set<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T>void debug(const multiset<T>&v){for(auto z:v)cout<<z<<" ";cout<<endl;}
template<typename T,size_t size>void debug(const array<T, size> &a){for(auto z:a)cout<<z<<" ";cout<<endl;}
template<typename T,typename V>void debug(const map<T,V>&v){for(auto z:v)cout<<"["<<z.first<<"]="<<z.second<<",";cout<<endl;}
template<typename T>vector<vector<T>>vec(ll x, ll y, T w){vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,-1,0,0,1,1,-1,-1};vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>auto make_v(size_t a,Ts... ts){return vector<decltype(make_v(ts...))>(a,make_v(ts...));}
template<typename T1, typename T2>ostream &operator<<(ostream &os, const pair<T1, T2>&p){return os << p.first << " " << p.second;}
template<typename T>ostream &operator<<(ostream &os, const vector<T> &v){for(auto &z:v)os << z << " ";cout<<"|"; return os;}
template<typename T>void rearrange(vector<int>&ord, vector<T>&v){
  auto tmp = v;
  for(int i=0;i<tmp.size();i++)v[i] = tmp[ord[i]];
}
template<typename Head, typename... Tail>void rearrange(vector<int>&ord,Head&& head, Tail&&... tail){
  rearrange(ord, head);
  rearrange(ord, tail...);
}
template<typename T> vector<int> ascend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]<v[j];});
  return ord;
}
template<typename T> vector<int> descend(const vector<T>&v){
  vector<int>ord(v.size());iota(ord.begin(),ord.end(),0);
  sort(ord.begin(),ord.end(),[&](int i,int j){return v[i]>v[j];});
  return ord;
}
template<typename T> vector<T> inv_perm(const vector<T>&ord){
  vector<T>inv(ord.size());
  for(int i=0;i<ord.size();i++)inv[ord[i]] = i;
  return inv;
}
ll FLOOR(ll n,ll div){assert(div>0);return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){assert(div>0);return n>=0?(n+div-1)/div:n/div;}
ll digitsum(ll n){ll ret=0;while(n){ret+=n%10;n/=10;}return ret;}
ll modulo(ll n,ll d){return (n%d+d)%d;};
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T acc(const vector<T>&v){return accumulate(v.begin(),v.end(),T(0));};
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
ll MULT(ll x,ll y){if(LLONG_MAX/x<=y)return LLONG_MAX;return x*y;}
ll POW2(ll x, ll k){ll ret=1,mul=x;while(k){if(mul==LLONG_MAX)return LLONG_MAX;if(k&1)ret=MULT(ret,mul);mul=MULT(mul,mul);k>>=1;}return ret;}
ll POW(ll x, ll k){ll ret=1;for(int i=0;i<k;i++){if(LLONG_MAX/x<=ret)return LLONG_MAX;ret*=x;}return ret;}
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge():id(-1){};
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T>revgraph(const Graph<T> &g){
  Graph<T>ret(g.size());
  for(int i=0;i<g.size();i++){
    for(auto e:g[i]){
      int to = e.to;
      e.to = i;
      ret[to].push_back(e);
    }
  }
  return ret;
}
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v;
    T w=1;
    cin>>u>>v;u-=indexed,v-=indexed;
    if(weighted)cin>>w;
    ret[u].emplace_back(v,w,es);
    if(!directed)ret[v].emplace_back(u,w,es);
  }
  return ret;
}
template<typename T>
Graph<T> readParent(int n,int indexed=1,bool directed=true){
  Graph<T>ret(n);
  for(int i=1;i<n;i++){
    int p;cin>>p;
    p-=indexed;
    ret[p].emplace_back(i);
    if(!directed)ret[i].emplace_back(p);
  }
  return ret;
}
template<typename T>
struct Compress{
	vector<T>v;
	Compress(){
	}
	Compress(const vector<T>&input){
		add(input);
    build();
	}
  template<typename... Args>
  Compress(const vector<T> &head,const Args& ...input){
    add(head, input...);
    build();
  }
  template<typename... Args>
  Compress(const T &head,const Args& ...input){
    add(head, input...);
    build();
  }
  void build(){
		sort(v.begin(), v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
  }
	void add(const vector<T>&add){
		v.insert(v.end(),add.begin(), add.end());
	}
  template<typename Head, typename ...Tail>
  void add(const Head& head,const Tail& ...tail){
    add(head);
    add(tail...);
  }
  void add(T val){
    v.push_back(val);
  }
  int next(T val){
    return lower_bound(v.begin(), v.end(), val) - v.begin();
  }
  int prev(T val){
    return upper_bound(v.begin(), v.end(), val) - v.begin() - 1;
  }
  bool exist(T val){
    return binary_search(v.begin(), v.end(), val);
  }
  T val(int x){
    return v[x];
  }
  vector<int>compress(const vector<T>&input){
    vector<int>ret(input.size());
    for(int i=0;i<input.size();i++)ret[i]=next(input[i]);
    return ret;
  }
  int operator[](T val){
    return next(val);
  }
  int size(){
    return v.size();
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<pair<P,P>>p;
  vector<P>q;
  rep(i,0,n-1){
    ll dx1,dy1,dx2,dy2;cin>>dx1>>dy1>>dx2>>dy2;
    dx1--;dy1--;dx2--;dy2--;
    p.EB(MP(dx1,dy1),MP(dx1+1,dy1));
    p.EB(MP(dx2,dy2),MP(dx2,dy2+1));
  }
  for(auto z:p){
    q.EB(z.fi);
    q.EB(z.se);
  }
  Compress mp(q);
  ll sz=mp.size();
  //debug(mp.v);
  Graph<ll>g(sz);
  auto dist=[](P x,P y){
    return abs(x.fi-y.fi)+abs(x.se-y.se);
  };
  vector<vector<ll>>cs(n);
  rep(i,0,mp.v.size()){
    cs[max(mp.v[i].fi,mp.v[i].se)].PB(i);
  }
  for(auto z:p){
    g[mp[z.fi]].EB(mp[z.se],1);
    g[mp[z.se]].EB(mp[z.fi],1);
    //cout<<mp[z.fi] spa mp[z.se]<<endl;
  }
  rep(i,0,n){
    rep(j,0,cs[i].size()){
      rep(o,j+1,cs[i].size()){
        ll d=dist(mp.val(cs[i][j]),mp.val(cs[i][o]));
        g[cs[i][j]].EB(cs[i][o],d);
        g[cs[i][o]].EB(cs[i][j],d);
        //cout<<cs[i][j] spa cs[i][o] spa d<<endl;
      }
    }
  }
  ll m;cin>>m;
  vector<ll>ret(m,INF);
  vector<vector<P>>gq(n);
  vector<P>u(m),v(m);
  rep(i,0,m){
    cin>>u[i].fi>>u[i].se>>v[i].fi>>v[i].se;
    u[i].fi--;u[i].se--;v[i].fi--;v[i].se--;
    ll ui=max(u[i].fi,u[i].se);
    ll vi=max(v[i].fi,v[i].se);
    if(ui>vi){
      swap(u[i],v[i]);
      swap(ui,vi);
    }
    if(ui==vi)ret[i]=dist(u[i],v[i]);
    gq[ui].EB(vi,i);
  }
  vector<ll>dp(mp.size(),INF);
  auto rec=[&](auto &&f, ll l,ll r)->void{
    if(l>=r)return;
    ll m=(l+r)/2;
    for(auto mid:cs[m]){
      rep(i,l,r){
        for(auto z:cs[i])dp[z]=INF;
      }
      dp[mid]=0;
      //debug(dp);
      rep(i,m,r){
        for(auto z:cs[i]){
          for(auto e:g[z]){
            chmin(dp[e.to],dp[z]+e.cost);
          }
        }
        for(auto z:cs[i]){
          for(auto e:g[z]){
            chmin(dp[e.to],dp[z]+e.cost);
          }
        }
      }
      rrep(i,l,m+1){
        for(auto z:cs[i]){
          for(auto e:g[z]){
            chmin(dp[e.to],dp[z]+e.cost);
          }
        }
        for(auto z:cs[i]){
          for(auto e:g[z]){
            chmin(dp[e.to],dp[z]+e.cost);
          }
        }
      }
      //cout<<l spa m spa r spa mid<<endl;
      //debug(dp);
      rep(i,l,m+1){
        for(auto z:gq[i]){
          if(z.fi>=m&&z.fi<r){
            for(auto x:cs[i])for(auto y:cs[z.fi]){
              chmin(ret[z.se],dist(u[z.se],mp.val(x))+dist(v[z.se],mp.val(y))+dp[x]+dp[y]);
            }
          }
        }
      }
    }
    f(f,l,m);
    f(f,m+1,r);
  };
  rec(rec,0,n);
  for(auto z:ret)cout<<z<<endl;
  return 0;
}