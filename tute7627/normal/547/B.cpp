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
int popcount(ll x){return __builtin_popcountll(x);};
int poplow(ll x){return __builtin_ctzll(x);};
int pophigh(ll x){return 63 - __builtin_clzll(x);};
template<typename T>
struct Segments{
  set<pair<T,T>>data;
  T len;
  Segments(){
    len = 0;
  };
  Segments(T l,T r){ //
    data.emplace(make_pair(l,r));
    len = r - l;
  }
  void unite(const Segments &segments){
    for(auto seg:segments.data){
      auto itr = data.lower_bound(seg);
      T lmin = seg.first, rmax = seg.second;
      if(itr != data.begin()){
        auto itr2 = prev(itr,1);
        if(itr2->second >= seg.first){
          chmin(lmin, itr2->first);
          chmax(rmax, itr2->second);
          len -= itr2->second - itr2->first;
          data.erase(itr2);
        }
      }
      while(itr != data.end()){
        if(itr->first <= seg.second){
          chmin(lmin, itr->first);
          chmax(rmax, itr->second);
          len -= itr->second - itr->first;
          itr = data.erase(itr);
        }
        else break;
      }
      data.emplace(lmin, rmax);
      len += rmax - lmin;
    }
  }
  void unite(T l,T r){
    unite(Segments<T>(l, r));
  }
  Segments operator+(const Segments segments) const{
    Segments ret = *this;
    ret.unite(segments);
    return ret;
  }
  Segments operator*(const Segments &segments)const {
    auto itr1 = this->data.begin();
    auto itr2 = segments.data.begin();
    Segments<T> ret;
    while(itr1 != this->data.end() && itr2 != segments.data.end()){
      T mi = max(itr1->first, itr2->first);
      T mx = min(itr1->second, itr2->second);
      if(mi < mx){
        ret.unite(Segments<T>(mi, mx));
      }
      if(itr1->second < itr2->second)itr1++;
      else itr2++;
    }
    return ret;
  }
  Segments intersect(T l,T r){
    return *this * Segments<T>(l, r);
  }
  void operator*=(const Segments &segments){
    *this = *this * segments; 
  }
  void diff(const Segments &segments){
    for(auto seg:segments.data){
      auto itr = data.lower_bound(seg);
      if(itr != data.begin()){
        auto itr2 = prev(itr,1);
        if(itr2->second > seg.first){
          len -= itr2->second - seg.first;
          if(itr2->first != seg.first)data.emplace(itr2->first,seg.first);
          if(itr2->second > seg.second){
            len += itr2->second - seg.second;
            data.emplace(seg.second, itr2->second);
          }
          data.erase(itr2);
        }
      }
      while(itr != data.end()){
        if(itr->second <= seg.second){
          len -= itr->second - itr->first;
          itr = data.erase(itr);
        }
        else{
          if(seg.second > itr->first){
            len -= seg.second - itr->first;
            data.erase(itr);
            if(itr->second != seg.second)data.emplace(seg.second,itr->second);
          }
          break;
        }
      }
    }
  }
  void diff(T l,T r){
    diff(Segments<T>(l, r));
  }
  Segments operator-(const Segments segments) const{
    Segments ret = *this;
    ret.diff(segments);
    return ret;
  }
  void print(){
    for(auto p:data){
      cout<<p.first <<" "<<p.second<<endl;
    }
  }
};
int main(){
  cin.tie(nullptr);
  ios_base::sync_with_stdio(false);
  ll res=0,buf=0;
  bool judge = true;
  ll n;cin>>n;
  vector<ll>a(n);
  rep(i,0,n)cin>>a[i];
  vector<ll>ord(n);
  iota(ALL(ord),0);
  sort(ALL(ord),[&](ll x,ll y){return a[x]>a[y];});
  ll pre=0;
  ll mx=0;
  vector<ll>ret(n);
  Segments<ll>seg;
  for(auto i:ord){
    seg.unite(i,i+1);
    auto p=--seg.data.upper_bound(MP(i,INF));
    //cout<<p->fi spa p->se spa i<<endl;
    chmax(mx,p->se-p->fi);
    //cout<<a[i] spa mx<<endl;
    rep(j,pre,mx)ret[j]=a[i];
    pre=mx;
  }
  debug(ret,n);
  return 0;
}