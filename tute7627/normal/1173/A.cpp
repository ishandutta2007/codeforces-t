#include<bits/stdc++.h>
using namespace std;

#define ld long double
#define ll long long
#define ALL(a)  (a).begin(),(a).end()
#define ALLR(a)  (a).rbegin(),(a).rend()
#define spa << " " <<
#define MP make_pair
ll MOD = 1e9+7;
//ll MOD = 998244353;
ll INF = 1e18;
void chmin(ll &a,ll b){if(a>b)a=b;}
void chmax(ll &a,ll b){if(a<b)a=b;}
void pmod(ll &a,ll b){a=(a+b)%MOD;}
void qmod(ll &a,ll b){a=(a*b)%MOD;}
void ans1(bool x){if(x) cout<<"Yes"<<endl;else cout<<"No"<<endl;}
void ans2(bool x){if(x) cout<<"YES"<<endl;else cout<<"NO"<<endl;}
void ans3(bool x){if(x) cout<<"Yay!"<<endl;else cout<<":("<<endl;}
void ans(bool x, ll y, ll z){if(x)cout<<y<<endl;else cout<<z<<endl;}   


int main(){
  ll i,j,o;
  ll result=0,buf=0,buf1=0,buf2=0,buf3=0,buf4=0;
  bool judge = true;
  ll x,y,z; cin>>x>>y>>z;
  if(x>y+z)cout<<"+"<<endl;
  else if(y>x+z)cout<<"-"<<endl;
  else if(x==y&&z==0)cout<<0<<endl;
  else cout<<"?"<<endl;


  return 0;
}