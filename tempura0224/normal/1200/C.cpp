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


ll gcd(ll x, ll y){
    return y?gcd(y,x%y):x;
}
int main(){
    ll n,m,q;
    cin>>n>>m>>q;
    ll g = gcd(n,m);
    while(q--){
        ll sx,sy,tx,ty;
        cin>>sx>>sy>>tx>>ty;
        --sy;--ty;
        if(sx==1)sy/=(n/g);
        else sy/=(m/g);
        if(tx==1)ty/=(n/g);
        else ty/=(m/g);
        cout<<(sy==ty?"YES":"NO")<<endl;
    }
    return 0;
}