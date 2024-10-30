#include <bits/stdc++.h>
using namespace std;

#define PII pair<int, int>
#define VI vector<int>
#define VPII vector<PII>
#define LL long long
#define f first
#define s second
#define MP make_pair
#define PB push_back
#define endl '\n'
#define ALL(c) (c).begin(), (c).end()
#define SIZ(c) (int)(c).size()
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, b, e) for (int i = (b); i <= (int)(e); i++)
#define FORD(i, b, e) for (int i = (b); i >= (int)(e); i--)
#define ll long long
#define st f
#define nd s
#define pb PB
#define mp MP
#define eb emplace_back
const int inf = 1e9 + 7;
const LL INF = 1e18L + 7;

#define sim template<class n
sim, class s> ostream & operator << (ostream &p, pair<n, s> x)
{return p << "<" << x.f << ", " << x.s << ">";}
sim> auto operator << (ostream &p, n y) ->
typename enable_if<!is_same<n, string>::value, decltype(y.begin(), p)>::type
{int o = 0; p << "{"; for (auto c : y) {if (o++) p << ", "; p << c;} return p << "}";}
void dor() {cerr << endl;}
sim, class...s> void dor(n p, s...y) {cerr << p << " "; dor(y...);}
sim, class s> void mini(n &p, s y) {if (p > y) p = y;}
sim, class s> void maxi(n &p, s y) {if (p < y) p = y;}

#ifdef DEB
#define debug(...) dor(__FUNCTION__, ":", __LINE__, ": ", __VA_ARGS__)
#else
#define debug(...)
#endif

#define I(x) #x " =", (x), " "
#define A(a, i) #a "[" #i " =", i, "] =", a[i], " "
const int M = 1024 * 512;

void solve()
{
	int n, s, ex = 1;
	scanf("%d%d", &s, &n);
	vector<int> V;
	while (s)
	{
		while (s % 10)
		{
			V.PB(ex);
			s--;
		}
		s /= 10;
		ex *= 10;
	}
	while (SIZ(V) < n)
	{
		sort(ALL(V));
		int ind = 0;
		while (V[ind] < 10)
		{
			ind++;
		}
		int x = V[ind];
		swap(V[ind], V.back());
		V.pop_back();
		FOR(i, 1, 10)
		{
			V.PB(x / 10);
		}
	}
	while (SIZ(V) > n)
	{
		int x = V.back();
		V.pop_back();
		V.back() += x;
	}
	for (auto x : V)
	{
		printf("%d ", x);
	}
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	while (t--)
	{
		solve();
	}
}