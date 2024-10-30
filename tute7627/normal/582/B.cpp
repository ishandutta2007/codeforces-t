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
template< class T , int maxsize>
struct SquareMatrix {
  using arr = array <T, maxsize>;
  using sqmat = array <arr, maxsize>;
  sqmat A;
  ll n;
  static const T iden = 0;
  static const T zero = -INF;
  const T add(T x, T y){
    return max(x,y);
  }
  const T mul(T x, T y){
    return x + y;
  }
  sqmat zeros(){
    sqmat mat;
    for(ll i=0;i<maxsize;i++)for(ll j=0;j<maxsize;j++)mat[i][j]=zero;
    return mat;
  }
  SquareMatrix() {
    n = maxsize;
    A = zeros();
  }
  SquareMatrix(size_t N) : n(N){
    A = zeros();
  };
  SquareMatrix(vector<vector<T>>v):n(v.size()){
    for(ll i=0;i<n;i++)for(ll j=0;j<n;j++)A[i][j]=v[i][j];
  };
  inline const arr &operator[](int k) const {
    return (A[k]);
  }

  inline arr &operator[](int k) {
    return (A[k]);
  }
  static SquareMatrix I(size_t N){
    SquareMatrix mat(N);
    for(int i = 0; i < N; i++) mat[i][i] = mat.iden;
    return (mat);
  }
  SquareMatrix &operator+=(const SquareMatrix &B) {
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        (*this)[i][j] = add((*this)[i][j], B[i][j]);
    return (*this);
  }

  SquareMatrix &operator*=(const SquareMatrix &B) {
    sqmat C = zeros();
    for(int i = 0; i < n; i++)
      for(int j = 0; j < n; j++)
        for(int k = 0; k < n; k++)
          C[i][j] = add(C[i][j],mul((*this)[i][k] , B[k][j]));
    A.swap(C);
    return (*this);
  }
  SquareMatrix &operator^=(long long k) {
    SquareMatrix B = SquareMatrix::I(n);
    while(k > 0) {
      if(k & 1) B *= *this;
      *this *= *this;
      k >>= 1LL;
    }
    A.swap(B.A);
    return (*this);
  }

  SquareMatrix operator+(const SquareMatrix &B) const {
    return (SquareMatrix(*this) += B);
  }

  SquareMatrix operator*(const SquareMatrix &B) const {
    return (SquareMatrix(*this) *= B);
  }

  SquareMatrix operator^(const long long k) const {
    return (SquareMatrix(*this) ^= k);
  }

  friend ostream &operator<<(ostream &os, SquareMatrix p) {
    for(int i = 0; i < p.n; i++) {
      os << "[";
      for(int j = 0; j < p.n; j++) {
        os << p[i][j] << (j + 1 == p.n ? "]\n" : ",");
      }
    }
    return (os);
  }
};
template<typename T>
map<T,ll> compress(vector<T> &v){
  sort(ALL(v));
  v.erase(unique(ALL(v)),v.end());
  map<T, ll> ret;
  for(ll i=0;i<(ll)v.size();i++)
    ret[v[i]]=i;
  return ret;
}
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,t;cin>>n>>t;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  using SQ=SquareMatrix<ll,105>;
  map<ll,ll>mp;
  auto val=a;
  val.PB(0);
  mp=compress(val);
  rep(i,0,n)a[i]=mp[a[i]];
  ll sz=mp.size();
  SQ mat(sz);
  rep(i,0,sz){
    vector<ll>dp(sz,-INF);
    dp[i]=0;
    rep(j,0,n){
      rrep(o,0,a[j]+1)chmax(dp[a[j]],dp[o]+1);
    }
    //debug(dp,sz);
    rep(j,0,sz)mat[i][j]=dp[j];
  }
  //debug(a,n);
  //cout<<mat<<endl;
  mat^=t;
  //cout<<mat<<endl;
  rep(i,0,sz)chmax(res,mat[0][i]);
  cout<<res<<endl;
  return 0;
}