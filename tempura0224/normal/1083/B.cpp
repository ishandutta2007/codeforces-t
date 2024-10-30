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
    ll n,k;
    cin>>n>>k;
    string s,t;
    cin>>s>>t;
    ll diff=0;
    ll ans=0;
    rep(i,n){
        if(diff>=k){
            ans+=k;
            continue;
        }
        if(s[i]!=t[i]){
            if(s[i]=='b')--diff;
            else ++diff;
        }
        ans+=max(min(k,diff+1),0LL);
        diff<<=1;
    }
    cout<<ans<<endl;
    return 0;
}