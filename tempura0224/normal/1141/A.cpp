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
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
typedef long long ll;
typedef pair<int,int> pint;
typedef pair<ll,int> pli;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int n,m;
    cin>>n>>m;
    if(m%n){
        cout<<-1<<endl;
        return 0;
    }
    int ret=m/n;
    int ans=0;
    while(ret%3==0){
        ret/=3;
        ++ans;
    }
    while(ret%2==0){
        ret/=2;
        ++ans;
    }
    if(ret==1){
        cout<<ans<<endl;
    }
    else cout<<-1<<endl;
    return 0;
}