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

const int inf=((1LL<<31)-1);
const int MOD=1e9+7;
const int N=0;

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
    string s;
    int ans=0;
    cin>>s;
    REP(i,0,s.length()){
        int j=i;
        while (s[j+1]==s[i]) j++;
        ans+=((j-i+1)%2==0);
        i=j;
    }
    cout<<ans;
}