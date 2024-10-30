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
struct edge {
  ll to,cost;
  edge(ll x,ll y):to(x),cost(y){};
};

int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n,m,k;cin>>n>>m>>k;
  ll sz=k;
  auto ng=make_v(sz,sz,sz,sz,false);
  vector<vector<edge>>g(n);
  vector<vector<P>>gr(n);
  rep(i,0,m){
    ll u,v,w;cin>>u>>v>>w;u--;v--;
    g[u].EB(v,w);
  }
  rep(i,0,n){
    sort(ALL(g[i]),[&](edge x,edge y){
      return x.cost<y.cost;
    });
    ll d=g[i].size();
    rep(j,0,d){
      gr[g[i][j].to].EB(d-1,j);
    }
  }
  rep(i,0,n){
    sort(ALL(gr[i]));
    rep(j,0,(ll)gr[i].size()-1){
      if(gr[i][j]==gr[i][j+1])ng[gr[i][j].fi][gr[i][j].se][gr[i][j].fi][gr[i][j].se]=true;
    }
    gr[i].erase(unique(ALL(gr[i])),gr[i].end());
    ll gsz=gr[i].size();
    rep(p,0,gsz)rep(q,0,gsz){
      if(p==q)continue;
      //cout<<i spa p spa q spa gr[i][p] spa gr[i][q]<<endl;
      ng[gr[i][p].fi][gr[i][p].se][gr[i][q].fi][gr[i][q].se]=true;
    }
  }
  auto g2=vec(sz,sz,vector<P>());
  auto t=vec(sz,sz,false);
  rep(i,0,sz)rep(j,0,sz)rep(p,i,sz)rep(q,0,sz){
    if(!ng[i][j][p][q])continue;
    if(i==p&&j==q){
      t[i][j]=true;
    }
    if(i==p)continue;
    g2[i][j].EB(p,q);
  }
  //cout<<-1<<endl;
  {
    auto dfs=[&](auto &&f,ll d)->void{
      if(d==sz){
        res++;
        return;
      }
      rep(i,0,d+1){
        if(t[d][i])continue;
        queue<P>que;
        for(auto z:g2[d][i]){
          if(!t[z.fi][z.se]){
            t[z.fi][z.se]=true;
            que.emplace(z.fi,z.se);
          }
        }
        f(f,d+1);
        while(!que.empty()){
          auto z=que.front();
          t[z.fi][z.se]=false;
          que.pop();
        }
      }
    };
    dfs(dfs,0);
    cout<<res<<endl;
  }
  return 0;
}