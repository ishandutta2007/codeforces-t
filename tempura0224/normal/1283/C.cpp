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
    vector<int> a(n),used(n);
    rep(i,n){
        cin>>a[i];
        if(a[i])used[a[i]-1]=1;
    }
    int cur = 0;
    int st = 0;
    rep(i,n){
        if(!a[i] && !used[i]){
            while(used[st] || st==i){
                ++st;
                if(st==n)st=0;
            }
            a[i]=st+1;
            used[st]=1;
        }
    }
    rep(i,n){
        if(!a[i] ){
            while(used[st] || st==i){
                ++st;
                if(st==n)st=0;
            }
            a[i]=st+1;
            used[st]=1;
        }
    }
    rep(i,n)cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}