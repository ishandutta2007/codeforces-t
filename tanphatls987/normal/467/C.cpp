#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <math.h>
#include <deque>
#include <vector>
#include <queue>

using namespace std;

#define X first
#define Y second
#define INPUT freopen(".inp","r",stdin)
#define OUTPUT freopen(".out","w",stdout)
#define FOR(i,l,r) for(int i=l;i<=r;i++)
#define REP(i,l,r) for(int i=l;i<r;i++)
#define FORD(i,l,r) for(int i=l;i>=r;i--)
#define REPD(i,l,r) for(int i=l;i>r;i--)
#define ENDL printf("\n")
#define inf 1000000

const int MOD=1000000007;
const int N=5010;

typedef long long ll;

int n,m,k;
ll a[N],v,f[N][N]={0};
void prepare(){
    scanf("%d%d%d",&n,&m,&k);
    FOR(i,1,n) scanf("%lld",&v),a[i]=a[i-1]+v;
}
void solve()
{
    FOR(i,m,n)
        FOR(j,1,i/m) f[i][j]=max(f[i-1][j],f[i-m][j-1]+a[i]-a[i-m]);
    printf("%lld",f[n][k]);
}
int main(){
    prepare();
    solve();
}