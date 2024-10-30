#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define LL long long
#define PLL pair<LL, LL>
#define LD long double
#define VI vector<int>
#define VPII vector<PII>
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define pb pop_back
#define FOR(a,s,d) for (int a = (s); a <= (int)(d); ++a)
#define FORD(a,s,d) for (int a = (s); a >= (int)(d); --a)
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define RE(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ALL(x) x.begin(), x.end()
#define siz(x) ((int)x.size())
#define Sim template <class s
Sim, class d> ostream & operator<<(ostream &os, pair<s,d> x){return os << "<" << x.F << ", " <<
  x.S << "> ";}
Sim> auto operator<<(ostream &os, s x) -> typename enable_if<!is_same<s,string>::value,
  decltype(x.begin(), os)>::type
{ int o = 0; os << "{"; for (auto c : x) {if(o++) os << ", "; os << c;}return os << "} ";}
void dor() {cerr << endl;}
Sim, class ...t> void dor(s x, t...y) {cerr << x << " "; dor(y...);}
#ifdef DEB
#define debug(c...) dor(__FUNCTION__, ":", __LINE__, ": ", c)
#else
#define debug(...)
#endif
const int M = 1024 * 128;

int n;
vector<int> V[M];

int main()
{
  //ios_base::sync_with_stdio(0);
  //cin.tie(0);
  scanf("%d", &n);
  for (int i = 1; i < n; i++)
  {
    int a, b;
    scanf("%d%d", &a, &b);
    V[a].PB(b);
    V[b].PB(a);
  }
  int v = 1, ile = 0;
  for (int i = 1; i <= n; i++)
  {
    if (siz(V[i]) > 2)
    {
      v = i;
      ile++;
    }
  }
  if (ile > 1)
  {
    printf("No\n");
    return 0;
  }
  printf("Yes\n%d\n", siz(V[v]));
  for (auto x : V[v])
  {
    int xx = x, pre = v;
    while (siz(V[xx]) != 1)
    {
      for (auto y : V[xx])
      {
        if (y != pre)
        {
          pre = xx;
          xx = y;
          break;
        }
      }
    }
    printf("%d %d\n", v, xx);
  }
  return 0;
}