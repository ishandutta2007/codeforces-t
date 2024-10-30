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
  ll t;cin>>t;
  while(t--){
    string s;cin>>s;
    ll n=s.size();
    auto v=vec(n,10,0LL);
    vector<ll>now(10);
    rep(i,0,n){
      v[i]=now;
      now[s[i]-'0']++;
    }
    string ret;
    rrep(i,0,n){
      if(s[i]=='0'||(i==0&&s[i]=='1'))continue;
      bool bit=false;
      bool bit2=false;
      ll num=0;
      rep(j,0,10){
        if(v[i][j]&1){
          num++;
          if(i==0&&j==0)continue;
          if(j<s[i]-'0')bit=true;
          if(j+1==s[i]-'0')bit2=true;
        }
      }
      if(num-(2*bit-1)>n-i-1)continue;
      ret=s;
      vector<char>c;
      //cout<<i spa bit spa num<<endl;debug(v[i],10);
      if((bit&&num-bit==n-i-1)||bit2){
        rrep(j,0,s[i]-'0'){
          if(v[i][j]&1){
            v[i][j]--;
            //cout<<i spa j<<endl;
            ret[i]=j+'0';
            break;
          }
        }
      }
      else{
        ret[i]--;
        c.PB(ret[i]);
      }
      rep(j,0,10)if(v[i][j]&1)c.PB('0'+j);
      rep(j,i+1,n)ret[j]='9';
      sort(ALLR(c));
      //cout<<ret spa c.size()<<endl;
      rrep(j,0,n){
        if(c.empty())break;
        ret[j]=c.back();
        c.pop_back();
      }
      break;
    }
    if(ret.size()==0){
      cout<<string(n-2,'9')<<endl;
    }
    else cout<<ret<<endl;
  }
  return 0;
}