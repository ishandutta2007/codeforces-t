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
    int n;
    cin>>n;
    vector<int>a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    if(a.size()>3){
        cout<<-1<<endl;
    }
    else if(a.size()==3){
        if(a[1]-a[0]==a[2]-a[1]){
            cout<<a[1]-a[0]<<endl;
        }
        else cout<<-1<<endl;
    }
    else if(a.size()==2){
        if((a[1]-a[0])%2)cout<<a[1]-a[0]<<endl;
        else cout<<(a[1]-a[0])/2<<endl;
    }
    else cout<<0<<endl;
    return 0;
}