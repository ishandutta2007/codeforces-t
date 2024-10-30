#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define PLL pair<LL, LL>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define LD long double
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define pb pop_back
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, b, e) for(int i = (b); i <= (int)(e); ++i)
#define FORD(i, b, e) for(int i = (b); i >= (int)(e); --i)

#define Sim template<class n
Sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
Sim> auto operator << (ostream &p, n y) -> 
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type 
{int o = 0; p << "{"; for(auto c: y) {if(o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
Sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
Sim, class s> void mini(n &p, s y) {if(p>y) p = y;}
Sim, class s> void maxi(n &p, s y) {if(p<y) p = y;}
#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif 

#define I(x) #x " = ", (x), " "
#define A(a, i) #a "[" #i " = ", i, "] = ", a[i], " "
const int M = 55;

struct ogr
{
	int l, r, h, c;
};

int n, h, m;
vector<ogr> V[M][M];
int dp[M][M][M];

int main()
{
	//ios_base::sync_with_stdio(0);
	//cin.tie(NULL);
	scanf("%d%d%d", &n, &h, &m);
	FOR(i, 1, m)
	{
		ogr x;
		scanf("%d%d%d%d", &x.l, &x.r, &x.h, &x.c);
		FOR(j, 1, n)
		{
			FOR(k, j, n)
			{
				if (j <= x.l && k >= x.r)
				{
					V[j][k].PB(x);
				}
			}
		}
	}
	FOR(i, 1, n)
	{
		FOR(j, 1, n - i + 1)
		{
			int l = j, r = j + i - 1;
			FOR(w, 1, h)
			{
				maxi(dp[l][r][w], dp[l][r][w - 1]);
				FOR(k, l, r)
				{
					int tmp = w * w;
					for (auto x : V[l][r])
					{
						if (x.l <= k && x.r >= k && x.h < w)
						{
							tmp -= x.c;
						}
					}
					maxi(dp[l][r][w], dp[l][k - 1][w] + dp[k + 1][r][w] + tmp);
				}
			}
		}
	}
	printf("%d\n", dp[1][n][h]);
	return 0;
}