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
#define rrep(i,n,m) for(ll i = (m) - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD1 = 1e9+7;
const ll MOD9 = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
bool chmin(T &a,T b){if(a>b){a=b;return true;}else return false;}
template<typename T>
bool chmax(T &a,T b){if(a<b){a=b;return true;}else return false;}
ll median(ll a,ll b, ll c){return a+b+c-max({a,b,c})-min({a,b,c});}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
template<typename T1,typename T2>
void ans(bool x,T1 y,T2 z){if(x)cout<<y<<endl;else cout<<z<<endl;}  
template<typename T>
void debug(vector<vector<T>>&v,ll h,ll w){for(ll i=0;i<h;i++)
{cout<<v[i][0];for(ll j=1;j<w;j++)cout spa v[i][j];cout<<endl;}};
void debug(vector<string>&v,ll h,ll w){for(ll i=0;i<h;i++)
{for(ll j=0;j<w;j++)cout<<v[i][j];cout<<endl;}};
template<typename T>
void debug(vector<T>&v,ll n){if(n!=0)cout<<v[0];
for(ll i=1;i<n;i++)cout spa v[i];cout<<endl;};
template<typename T>
vector<vector<T>>vec(ll x, ll y, T w){
  vector<vector<T>>v(x,vector<T>(y,w));return v;}
ll gcd(ll x,ll y){ll r;while(y!=0&&(r=x%y)!=0){x=y;y=r;}return y==0?x:y;}
vector<ll>dx={1,0,-1,0,1,1,-1,-1};
vector<ll>dy={0,1,0,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}  
//maxa=10^7150ms,78MB10^81800ms,780MB
struct osa_k{
  ll maxa;
  vector<ll>data;//data[i]:i
  osa_k(ll a):maxa(a){
    data.assign(maxa+1,1LL);
    build();
  }
  void build(){
    for(ll i=0;i<=maxa;i++)data[i] = i;
    for(ll i=2;i*i<=maxa;i++){
      if(data[i] < i)continue;
      for(ll j=i*i;j<=maxa;j+=i){
        if(data[j] == j)data[j] = i;
      }
    }
  }
  bool isPrime(ll x){
    return (x >= 2)&&(data[x] == x);
  }
  map<ll,ll>factoring(ll x){
    map<ll,ll>ret;
    while(x > 1){
      ret[data[x]]++;
      x /= data[x];
    }
    return ret;
  }
  vector<ll>divisor_enum(ll x){
    auto v = factoring(x);
    vector<ll>ret;
    ret.push_back(1);
    for(auto z:v){
      ll sz = ret.size();
      ll tmp = z.fi;
      for(ll i=0;i<z.se;i++){
        for(ll j=0;j<sz;j++){
          ret.push_back(ret[j] * tmp);
        }
        tmp *= z.fi;
      }
    }
    sort(ret.begin(),ret.end());//ok
    return ret;
  }
};
//0-indexed

template<typename T>
map<T,ll> compress(vector<T> &v){
  auto t=v;
  sort(ALL(t));
  t.erase(unique(ALL(t)),t.end());
  map<T, ll> ret;
  for(ll i=0;i<(ll)t.size();i++)
    ret[t[i]]=i;
  return ret;
}
vector<ll>dist(1000005);
ll bfs(ll k,vector<vector<ll>>&g){
  queue<pair<P,ll>> q;
  ll mi=INF;
  ll n=g.size();
  q.emplace(MP(k,0),-1);
  fill(dist.begin(),dist.begin()+n,INF);
  while(!q.empty()){
    ll x=q.front().fi.fi;
    ll len=q.front().fi.se;
    ll from=q.front().se;
    if(dist[x]==INF){
      dist[x]=len;
      for(ll i=0;i<g[x].size();i++){
        if(g[x][i]!=from){
          q.emplace(MP(g[x][i],len+1),x);
        }
      }
    }
    else chmin(mi,dist[x]+len);
    q.pop();
  }
  return mi;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  osa_k osak(1000005);
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<ll>val;
  rep(i,2,1000005){
    if(osak.isPrime(i))val.PB(i);
  }
  auto mp=compress(val);
  //cout<<val.size()<<endl;
  map<ll,ll>cnt;
  map<ll,ll>cnt2;
  ll sz=mp.size();
  vector<vector<ll>>g(sz);
  rep(i,0,n){
    auto fact=osak.factoring(a[i]);
    cnt2[a[i]]++;
    for(auto itr=fact.begin();itr!=fact.end();){
      if(itr->se%2==0)itr=fact.erase(itr);
      else itr++;
    }
    if(fact.size()==0){
      cout<<1<<endl;
      return 0;
    }
    else if(fact.size()==1){
      cnt[(fact.begin())->fi]++;
    }
    else{
      ll u=(fact.begin())->fi;
      ll v=(++fact.begin())->fi;
      g[mp[u]].EB(mp[v]);
      g[mp[v]].EB(mp[u]);
    }
  }
  for(auto z:cnt){
    if(z.se>=2){
      cout<<2<<endl;
      return 0;
    }
  }
  for(auto z:cnt2){
    //cout<<z.fi spa z.se<<endl;
    if(z.se>=2){
      cout<<2<<endl;
      return 0;
    }
  }
  res=INF;
  rep(i,0,200){
    ll d=bfs(i,g);
    chmin(res,d);
    P p(INF,INF);
    rep(j,0,sz){
      if(i==j||cnt[val[j]]==0)continue;
      if(cnt[val[i]]!=0)chmin(res,dist[j]+2);
      if(p.fi>dist[j]){
        p.se=p.fi;
        p.fi=dist[j];
      }
      else if(p.se>dist[j]){
        p.se=dist[j];
      }
    }
    chmin(res,p.fi+p.se+2);
  }
  ans(res==INF,-1,res);
  return 0;
}