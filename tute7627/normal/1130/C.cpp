#include<bits/stdc++.h>
using namespace std;

#define endl '\n'
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define test cout<<"test"<<endl;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define EB emplace_back
#define rep(i,n,m) for(ll i = n; i < (ll)(m); i++)
#define rrep(i,n,m) for(ll i = m - 1; i >= (ll)(n); i--)
using ll = long long;
using ld = long double;
const ll MOD = 1e9+7;
//const ll MOD = 998244353;
const ll INF = 1e18;
using P = pair<ll, ll>;
template<typename T>
void chmin(T &a,T b){if(a>b)a=b;}
template<typename T>
void chmax(T &a,T b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void pmod(ll &a,ll b,ll c){a=(b+c)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void qmod(ll &a,ll b,ll c){a=(b*c)%MOD;}
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
struct UnionFind {
  vector<ll> data;
  UnionFind(ll size) : data(size, -1) { }
  bool unite(ll x, ll y) {
    x = root(x); y = root(y);
    if (x != y) {
      if (data[y] < data[x]) swap(x, y);
      data[x] += data[y]; data[y] = x;
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
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<string>a(n);
  UnionFind uf(n*n);
  ll r1,r2,c1,c2;cin>>r1>>c1>>r2>>c2;
  r1--;c1--;r2--;c2--;
  rep(i,0,n)cin>>a[i];
  rep(i,0,n)rep(j,0,n){
    if(a[i][j]=='0'){
      rep(o,0,4){
        ll x=i+dx[o],y=j+dy[o];
        if(x>=0&&x<n&&y>=0&&y<n&&a[x][y]=='0'){
          uf.unite(i*n+j,x*n+y);
        }
      }
    }
  }
  res=INF;
  rep(i,0,n)rep(j,0,n)rep(p,0,n)rep(q,0,n){
    ll l=r1*n+c1,r=r2*n+c2,x=i*n+j,y=p*n+q;
    if(uf.find(l,x)&&uf.find(r,y)){
      //cout<<i spa j spa p spa q spa r1 spa r2 spa c1 spa c2 spa l spa r<<endl;
      chmin(res,abs(i-p)*abs(i-p)+abs(j-q)*abs(j-q));
    }
  }
  cout<<res<<endl;
  return 0;
}