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

void solve(){
  ll n,x,y;cin>>n>>x>>y;
  vector<ll>b(n);
  rep(i,0,n)cin>>b[i],b[i]--;
  vector<vector<ll>>v(n+1);
  rep(i,0,n){
    v[b[i]].PB(i);
  }
  ll scrap=-1;
  rep(i,0,n+1)if(v[i].empty())scrap=i;
  vector<ll>ret(n,-1);
  priority_queue<P>que;
  ll ny=y,nx=x;
  rep(i,0,n+1)if(!v[i].empty())que.emplace((ll)v[i].size()-1,i);
  while(!que.empty()&&ny){
    if((ny-nx)%2==1){
      if(y!=n){
        if(que.size()<2)break;
        vector<P>p(2);
        rep(i,0,2){
          p[i]=que.top();
          que.pop();
        }
        ret[v[p[0].se][p[0].fi]]=p[1].se;
        ret[v[p[1].se][p[1].fi]]=scrap;
        rep(i,0,2){
          p[i].fi--;
          if(p[i].fi>=0)que.push(p[i]);
        }
        ny--;
      }
      else{
        if(que.size()<3)break;
        vector<P>p(3);
        rep(i,0,3){
          p[i]=que.top();
          que.pop();
        }
        rep(i,0,3)ret[v[p[i].se][p[i].fi]]=p[(i+1)%3].se;
        rep(i,0,3){
          p[i].fi--;
          if(p[i].fi>=0)que.push(p[i]);
        }
        ny-=3;
      }
    }
    else if(nx<ny){
      if(que.size()<2)break;
      vector<P>p(2);
      rep(i,0,2){
        p[i]=que.top();
        que.pop();
      }
      ret[v[p[0].se][p[0].fi]]=p[1].se;
      ret[v[p[1].se][p[1].fi]]=p[0].se;
      rep(i,0,2){
        p[i].fi--;
        if(p[i].fi>=0)que.push(p[i]);
      }
      ny-=2;
    }
    else{
      auto p=que.top();
      que.pop();
      ret[v[p.se][p.fi]]=p.se;
      p.fi--;
      //cout<<p<<endl;
      if(p.fi>=0)que.push(p);
      ny--;nx--;
    }
    //cout<<nx spa ny<<endl;
    //debug(ret,n);
  }
  //debug(ret,n);
  rep(i,0,n)if(ret[i]==-1)ret[i]=scrap;
  ans2(!nx&&!ny);
  if(!nx&&!ny){
    rep(i,0,n)ret[i]++;
    debug(ret,n);
  }
}

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll t;cin>>t;
  while(t--){
    solve();
  }
  return 0;
}