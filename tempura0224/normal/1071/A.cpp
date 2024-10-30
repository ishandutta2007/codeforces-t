#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    ll a,b;
    cin>>a>>b;
    ll n=0;
    while(n*(n+1)/2<=a+b)n++;
    --n;
    vector<int> va,vb;
    for(int i=n;i>0;i--){
        if(i<=a){
            va.push_back(i);
            a-=i;
        }
        else vb.push_back(i);
    }
    reverse(va.begin(),va.end());
    reverse(vb.begin(),vb.end());
    cout<<va.size()<<endl;
    for(auto e:va)printf("%d ",e);
    cout<<endl;
    cout<<vb.size()<<endl;
    for(auto e:vb)printf("%d ",e);
    cout<<endl;
    return 0;
}