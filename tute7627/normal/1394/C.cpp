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
template<typename T1, typename T2>
bool chmin(T1 &a,T2 b){if(a>b){a=b;return true;}else return false;}
template<typename T1, typename T2>
bool chmax(T1 &a,T2 b){if(a<b){a=b;return true;}else return false;}
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
vector<ll>dx={1,-1,0,0,1,1,-1,-1};
vector<ll>dy={0,0,1,-1,1,-1,1,-1};
template<typename T>
vector<T> make_v(size_t a,T b){return vector<T>(a,b);}
template<typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v(ts...))>(a,make_v(ts...));
}
template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2>&p){
  return os << p.first << " " << p.second;
}
//mt19937 mt(chrono::steady_clock::now().time_since_epoch().count());

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<string>s(n);
  vector<ll>a(n),b(n);
  rep(i,0,n){
    cin>>s[i];
    for(auto c:s[i]){
      if(c=='B')a[i]++;
      else b[i]++;
    }
  }
  vector<ll>cand;
  vector<ll>x={0,1,0,-1,1,-1,1,-1};
  vector<ll>y={1,0,-1,0,1,-1,-1,1};
  ll sz=8;
  rep(i,0,8){
    P mx(-INF,-1);
    rep(j,0,n)chmax(mx,MP(x[i]*a[j]+y[i]*b[j],j));
    cand.PB(mx.se);
  }
  auto f=[&](ll idx,ll ta,ll tb){
    ll da=a[idx]-ta,db=b[idx]-tb;
    if(da*db<0)return abs(da)+abs(db);
    else return max(abs(da),abs(db));
  };
  res=INF;;
  ll ka=-1,kb=-1;
  rep(i,0,500002){
    P mx1(-INF,-1);
    P mx2(-INF,-1);
    P mx3(-INF,-1);
    for(auto c:cand){
      chmax(mx1,MP(f(c,i,0),c));
      chmax(mx2,MP(f(c,i,2000000),c));
      chmax(mx3,MP(f(c,i,b[c]),c));
    }
    auto ff=[&](ll tb){
      return max({f(mx1.se,i,tb),f(mx2.se,i,tb),f(mx3.se,i,tb)});
    };
    ll l=-1,r=1000000;
    while(r-l>=3){
      ll m1=l+(r-l)/3;
      ll m2=l+(r-l)*2/3;
      if(ff(m1)<ff(m2))r=m2;
      else l=m1;
    }
    if((i!=0||l!=-1)&&chmin(res,ff(l+1)))ka=i,kb=l+1;
    if(chmin(res,ff(l+2)))ka=i,kb=l+2;
  }
  cout<<res<<endl;
  cout<<string(ka,'B')+string(kb,'N')<<endl;
  return 0;
}