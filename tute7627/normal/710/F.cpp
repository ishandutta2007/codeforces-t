//#define _GLIBCXX_DEBUG

#include<bits/stdc++.h>
using namespace std;

//#define endl '\n'
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
template<typename T> using PQ = priority_queue<T>;
template<typename T> using QP = priority_queue<T,vector<T>,greater<T>>;
template<typename T1, typename T2>bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>void debug(const T &v,ll h,ll w,string sv=" "){for(ll i=0;i<h;i++){cout<<v[i][0];for(ll j=1;j<w;j++)cout<<sv<<v[i][j];cout<<endl;}};
template<typename T>void debug(const T &v,ll n,string sv=" "){if(n!=0)cout<<v[0];for(ll i=1;i<n;i++)cout<<sv<<v[i];cout<<endl;};
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
ll FLOOR(ll n,ll div){return n>=0?n/div:(n-div+1)/div;}
ll CEIL(ll n,ll div){return n>=0?(n+div-1)/div:n/div;}
template<typename T>T min(const vector<T>&v){return *min_element(v.begin(),v.end());}
template<typename T>T max(const vector<T>&v){return *max_element(v.begin(),v.end());}
template<typename T>T reverse(const T &v){return T(v.rbegin(),v.rend());};
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>T poll(queue<T> &q){auto ret=q.front();q.pop();return ret;};
template<typename T>T poll(priority_queue<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(QP<T> &q){auto ret=q.top();q.pop();return ret;};
template<typename T>T poll(stack<T> &s){auto ret=s.top();s.pop();return ret;};
template< typename T = int >
struct edge {
  int to;
  T cost;
  int id;
  edge() = default;
  edge(int to, T cost = 1, int id = -1):to(to), cost(cost), id(id){}
  operator int() const { return to; }
};

template<typename T>
using Graph = vector<vector<edge<T>>>;
template<typename T>
Graph<T> readGraph(int n,int m,int indexed=1,bool directed=false,bool weighted=false){
  Graph<T> ret(n);
  for(int es = 0; es < m; es++){
    int u,v,w=1;
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
template<int iden, int size>
struct Trie{
  struct Node{
    array<int, size>nxt;
    vector<int>idx;
    int fail, len;
    Node(int l):fail(0), len(l){
      fill(nxt.begin(), nxt.end(), -1);
    }
  };
  vector<Node>data;
  Trie(){
    data.emplace_back(0);
  }
  int add(const string &s, int id=0){
    int pos=0;
    for(int i=0;i<s.size();i++){
      int c = s[i] - iden;
      if(data[pos].nxt[c]==-1){
        data[pos].nxt[c]=data.size();
        data.emplace_back(i+1);
      }
      pos = data[pos].nxt[c];
    }
    data[pos].idx.push_back(id);
		return pos;
  }
  int append(int pos,char cc){
		int c = cc - iden;
		if(data[pos].nxt[c]==-1){
			data[pos].nxt[c]=data.size();
      data.emplace_back(data[pos].len+1);
		}
		pos=data[pos].nxt[c];
		return pos;
	}
  vector<string>str;
  void build_str(int pos=0,string s=""){
    while(str.size()<=pos)str.push_back("");
    str[pos]=s;
    for(int i=0;i<size;i++){
      if(data[pos].nxt[i]!=-1){
        build_str(data[pos].nxt[i],s+char(i+iden));
      }
    }
  }
  void build_Ahocorasick(){
    //build_str();
    queue<int>que;
    for(int i=0;i<size;i++){
      if(data[0].nxt[i]!=-1){
        data[data[0].nxt[i]].fail=0;
        que.push(data[0].nxt[i]);
      }
      else{
        data[0].nxt[i]=0;
      }
    }
    while(!que.empty()){
      int pos = que.front();
      que.pop();
      for(int i=0;i<size;i++){
        if(data[pos].nxt[i]!=-1){
          data[data[pos].nxt[i]].fail = data[data[pos].fail].nxt[i];
          que.push(data[pos].nxt[i]);
        }
        else{
          data[pos].nxt[i]=data[data[pos].fail].nxt[i];
        }
      }
    }
  }
  vector<int>cnt;
  void build_cnt(){
    if(sg.empty())suffix_link();
    cnt.assign(data.size(),0);
    rep(i,0,data.size())cnt[i]=data[i].idx.size();
    auto dfs=[&](auto &&f,int k)->void{
      //cout<<str[k] spa cnt[k]<<endl;
      for(auto to:sg[k]){
        cnt[to]+=cnt[k];
        f(f,to);
      }
    };
    dfs(dfs,0);
  }
  ll aho_search(const string &s){
    ll ret=0;
    int now=0;
    for(int i=0;i<s.size();i++){
      int c = s[i] - iden;
      now=data[now].nxt[c];
      //cout<<i spa now spa cnt[now] spa str[now]<<endl;
      ret+=cnt[now];
    }
    return ret;
  }
  Graph<int> sg;
  void suffix_link(){
    assert(sg.empty());
    sg.resize(data.size());
    for(int i=1;i<data.size();i++){
      sg[data[i].fail].emplace_back(i);
    }
  }
};
using trie = Trie<'a',26>;
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  vector<trie>tria,trid;
  vector<vector<string>>stra,strd;
  auto build=[](trie &tri,vector<string>&str){
    for(auto &s:str)tri.add(s);
    tri.build_Ahocorasick();
    tri.build_cnt();
  };
  auto recalc=[&](vector<trie>&tri,vector<vector<string>>&str,string &add){
    tri.EB();
    str.EB(1,add);
    build(tri.back(),str.back());
    while(str.size()>1&&str[str.size()-1].size()==str[str.size()-2].size()){
      tri.pop_back();tri.pop_back();tri.EB();
      for(auto &s:str.back())str[str.size()-2].PB(s);
      str.pop_back();
      build(tri.back(),str.back());
    }
  };
  ll q;cin>>q;
  while(q--){
    ll t;cin>>t;
    string s;cin>>s;
    if(t==1)recalc(tria,stra,s);
    if(t==2)recalc(trid,strd,s);
    if(t==3){
      ll ret=0;
      //cout<<stra<<endl;
      for(auto &tr:tria){
        ret+=tr.aho_search(s);
        //cout<<ret<<endl;
      }
      //cout<<strd<<endl;
      for(auto &tr:trid){
        ret-=tr.aho_search(s);
        //cout<<ret<<endl;
      }
      cout<<ret<<endl;
    }
  }
  return 0;
}