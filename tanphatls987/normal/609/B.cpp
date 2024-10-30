#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("A.inp","r",stdin)
#define OUTPUT freopen("A.out","w",stdout)
#define FOR(i,l,r) for(auto i=(l);i<=(r);i++)
#define REP(i,l,r) for(auto i=(l);i<(r);i++)
#define FORD(i,l,r) for(auto i=(l);i>=(r);i--)
#define REPD(i,l,r) for(auto i=(l);i>(r);i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=20;

int n,m,a[N];
void prepare(){
    scanf("%d%d",&n,&m);
    int x;
    FOR(i,1,n) {
        scanf("%d",&x);
        a[x]++;
    }
}
ll solve(){
    ll ans=0;
    FOR(i,1,m)
        FOR(j,i+1,m) ans+=1LL*a[i]*a[j];
    return ans;
}
int main(){
    prepare();
    cout<<solve();
}