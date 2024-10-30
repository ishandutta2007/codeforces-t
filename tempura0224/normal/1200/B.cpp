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
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

int main(){
    int t;
    cin>>t;
    while(t--){
        ll n,m,k;
        cin>>n>>m>>k;
        vector<int> a(n);
        rep(i,n){
            cin>>a[i];
        }
        bool ok = true;
        rep(i,n-1){
            if(a[i]+m+k<a[i+1]){
                ok=false;
            }
            else if(a[i]+k>a[i+1]){
                ll can = max(0ll,a[i+1]-k);
                m += a[i]-can;
            }
            else {
                m -= a[i+1]-k-a[i];
            }
        }
        if(ok)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}