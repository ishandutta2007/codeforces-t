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
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());
template< int mod >
struct ModInt {
  int x;

  ModInt() : x(0) {}

  ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

  ModInt &operator+=(const ModInt &p) {
    if((x += p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator-=(const ModInt &p) {
    if((x += mod - p.x) >= mod) x -= mod;
    return *this;
  }

  ModInt &operator*=(const ModInt &p) {
    x = (int) (1LL * x * p.x % mod);
    return *this;
  }

  ModInt &operator/=(const ModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ModInt operator-() const { return ModInt(-x); }

  ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

  ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

  ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

  ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

  bool operator==(const ModInt &p) const { return x == p.x; }

  bool operator!=(const ModInt &p) const { return x != p.x; }

  ModInt inverse() const {
    int a = x, b = mod, u = 1, v = 0, t;
    while(b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ModInt(u);
  }

  ModInt pow(int64_t n) const {
    ModInt ret(1), mul(x);
    while(n > 0) {
      if(n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }
  friend ostream &operator<<(ostream &os, const ModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ModInt &a) {
    int64_t t;
    is >> t;
    a = ModInt< mod >(t);
    return (is);
  }

  static int get_mod() { return mod; }
};

template< typename T >
struct Combination {
  vector< T > _fact, _rfact, _inv;

  Combination(ll sz) : _fact(sz + 1), _rfact(sz + 1), _inv(sz + 1) {
    _fact[0] = _rfact[sz] = _inv[0] = 1;
    for(ll i = 1; i <= sz; i++) _fact[i] = _fact[i - 1] * i;
    _rfact[sz] /= _fact[sz];
    for(ll i = sz - 1; i >= 0; i--) _rfact[i] = _rfact[i + 1] * (i + 1);
    for(ll i = 1; i <= sz; i++) _inv[i] = _rfact[i] * _fact[i - 1];
  }

  inline T fact(ll k) const { return _fact[k]; }

  inline T rfact(ll k) const { return _rfact[k]; }

  inline T inv(ll k) const { return _inv[k]; }

  T P(ll n, ll r) const {
    if(r < 0 || n < r) return 0;
    return fact(n) * rfact(n - r);
  }

  T C(ll p, ll q) const {
    if(q < 0 || p < q) return 0;
    return fact(p) * rfact(q) * rfact(p - q);
  }
  
  T RC(ll p, ll q) const {
    if(q < 0 || p < q) return 0;
    return rfact(p) * fact(q) * fact(p - q);
  }

  T H(ll n, ll r) const {
    if(n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
using modint = ModInt< MOD1 >;modint pow(ll n, ll x){return modint(n).pow(x);}modint pow(modint n, ll x){return n.pow(x);}
//using modint=ld;
using Comb=Combination<modint>;

struct UnionFind {
  vector<ll> data;
  ll num;
  UnionFind(ll size) : data(size, -1) ,num(size){ }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
	  num--;
    }
    return x != y;
  }
  bool find(ll x, ll y) {
    return root(x) == root(y);
  }
  ll root(ll x) {
    return data[x] < 0 ? x : data[x] = root(data[x]);
  }
  ll size(ll x) {
    return -data[root(x)];
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,k;cin>>n>>m>>k;
  modint sz=1LL<<k;
  vector<ll>c(n);
  rep(i,0,n)cin>>c[i];
  vector<ll>u(m),v(m);
  map<ll,vector<ll>>mp;
  rep(i,0,m){
    cin>>u[i]>>v[i];u[i]--;v[i]--;
    mp[c[u[i]]^c[v[i]]].PB(i);
  }
  modint tmp=pow(2LL,n);
  modint ret=tmp*sz;
  UnionFind uf(n);
  for(auto &z:mp){
    ret-=tmp;
    queue<ll>que;
    for(auto i:z.se){
      if(uf.unite(u[i],v[i])){
        que.push(u[i]);
        que.push(v[i]);
      }
    }
    ret+=pow(2LL,uf.num);
    uf.num=n;
    while(!que.empty()){
      uf.data[que.front()]=-1;
      que.pop();
    }
  }
  cout<<ret<<endl;
  return 0;
}