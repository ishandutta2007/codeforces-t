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

int n, m;
VI V;

int32_t main()
{
	scanf("%d%d", &n, &m);
	int res = 0;
	FOR(i, 1, n)
	{
		if (res + (i - 1) / 2 > m)
		{
			break;
		}
		res += (i - 1) / 2;
		V.PB(i);
	}
	if (SIZ(V) == n && res < m)
	{
		printf("-1\n");
		return 0;
	}
	int a = m - res;
	debug(V, res, a);
	if (a != 0)
	{
		assert(SIZ(V) < n);
		V.PB(2 * V.back() - 2 * a + 1);
	}
	int st = max(V.back() * 3, 100000);
	int sz = SIZ(V);
	FOR(i, 1, n - sz)
	{
		V.PB(st + i * (2 * n + 1));
	}
	for (auto x : V)
	{
		printf("%d ", x);
	}
	printf("\n");
}