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
using namespace std;
#define REP(i,m,n) for(int i=(int)m ; i < (int) n ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;
int dx[4]={1,0,-1,0} , dy[4]={0,1,0,-1} ;

int main(){
   ll n,q;
   cin>>n>>q;
   while(q--){
       ll x,y;
       cin>>x>>y;
       if((x+y)%2){
           ll ret=(n*n+1)/2;
           ret+=n*(x-1)/2;
           y=(y+1)/2;
           printf("%lld\n",ret+y);
       }
       else {
           ll ret=(n*(x-1)+1)/2;
           y=(y+1)/2;
           printf("%lld\n",ret+y);
       }
   }
   return 0;
}