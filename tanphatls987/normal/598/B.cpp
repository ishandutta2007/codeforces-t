#include <bits/stdc++.h>

using namespace std;

#define X first
#define Y second
#define INPUT freopen("draft.inp","r",stdin)
#define OUTPUT freopen("draft.out","w",stdout)
#define FOR(i,l,r) for(auto i=l;i<=r;i++)
#define REP(i,l,r) for(auto i=l;i<r;i++)
#define FORD(i,l,r) for(auto i=l;i>=r;i--)
#define REPD(i,l,r) for(auto i=l;i>r;i--)
#define ENDL printf("\n")
#define debug 1

typedef long long ll;
typedef pair<int,int> ii;

const int inf=1e9;
const int MOD=1e9+7;
const int N=1e4+10;

string s;
char ts[N];
int main(){
    int n,l,r,k;
    cin>>s>>n;
    while (n--){
        cin>>l>>r>>k;
        l--;r--;
        int len=r-l+1;
        REP(i,0,len) ts[i]=s[l+i];
        REP(i,0,len) s[l+((i+k)%len)]=ts[i];
    }
    cout<<s;
}