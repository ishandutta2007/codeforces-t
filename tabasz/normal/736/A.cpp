#include<bits/stdc++.h>
using namespace std;
# ifdef DEB
# define debug(...) fprintf(stderr, __VA_ARGS__)
# else
# define debug(...)
#endif
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define LL long long
#define LD long double
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define pb pop_back
#define VI vector<int> 
#define VPI vector<PII> 
#define FOR(i,a,b) for(int i = (a); i <= (b); i++)
#define FORD(i,a,b) for(int i = (a); i >= (b); i--)
#define RE(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(int)(n)-1)
#define ALL(x) (x).begin(), (x).end()
#define siz(V) ((int)V.size())

LL n;
LL dp[1000];

int main()
{
  ios_base::sync_with_stdio(0);
  cin>> n;
  dp[1]=2;
  dp[0]=1;
  int tmp=0;
  while(dp[tmp+1]<=n)
  {
    dp[tmp+2]=dp[tmp]+dp[tmp+1];
    tmp++;
  }
  cout<< tmp << '\n';
  return 0;
}