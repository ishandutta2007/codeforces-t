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
    cin.tie(0);
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        rep(i,n)cin>>a[i];
        bool ok=false;
        rep(i,n-1){
            if(abs(a[i+1]-a[i])>=2){
                ok=true;
                cout<<"YES"<<endl;
                cout<<i+1<<" "<<i+2<<endl;
                break;
            }
        }
        if(!ok)cout<<"NO"<<endl;
    }
    return 0;
}