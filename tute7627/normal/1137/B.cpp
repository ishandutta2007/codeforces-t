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
vector<ll>z_algorithm(string s){
  ll n = s.size();
  vector<ll>ret(n,0);
  ret[0] = n;
  ll p = 1,len = 0;
  while(p < n){
    while(p+len < n && s[len] == s[p+len])len++;
    ret[p] = len;
    if(len == 0){p++; continue;}
    ll k = 1;
    while(p+k < n && k+ret[k] < len)ret[p+k] = ret[k], k++;
    p += k, len -= k;
  }
  return ret;
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  //cout<<fixed<<setprecision(10);
  ll res=0,buf=0;
  bool judge = true;
  string s,t;cin>>s>>t;
  auto v=z_algorithm(t);
  ll x=t.size();
  rep(i,1,t.size()){
    if(v[i]==t.size()-i){
      x=i;break;
    }
  }
  ll cnt0=0,cnt1=0;
  rep(i,0,s.size()){
    if(s[i]=='1')cnt1++;
    else cnt0++;
  }
  ll num0=0,num1=0,numx=0,numy=0;
  rep(i,0,t.size()){
    if(t[i]=='0')num0++;
    else num1++;
  }
  rep(i,0,x){
    if(t[t.size()-x+i]=='0')numx++;
    else numy++;
  }
  string r;
  if(num1<=cnt1&&num0<=cnt0){
    r+=t;
    cnt1-=num1;cnt0-=num0;
  }
  //cout<<x spa cnt0 spa cnt1 spa num0 spa num1 spa numx spa numy<<endl;
  while(cnt1>=numy&&cnt0>=numx){
    r+=t.substr(t.size()-x);
    cnt1-=numy;cnt0-=numx;
  }
  rep(i,0,cnt1)r+='1';
  rep(i,0,cnt0)r+='0';
  cout<<r<<endl;
  return 0;
}