#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <utility>
#include <stack>
#include <set>
#include <algorithm>
#include <bitset>
#include <functional>
#include <ctime>
#include <cassert>
#include <valarray>
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;
typedef vector< vector<int> > vvint;

#ifdef LOCAL
#define eprint() debugOutput()
#else
#define eprint() ;
#endif

const int P = (int) 1e9 + 7;
const int INF = 1e9 + 10;
const ll LINF = (ll) 2e18 + 10;
const double pi = 2 * atan2(1, 0);
const ld PI = 2 * atan2l(1, 0);
const double eps = 1e-8;
const ld EPS = 1e-12;
void debugOutput();

const int N = 4e5 + 10;
int n, a[N], b[N];

void solve()
{
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin >> a[i];
	for (int j = 0; j < n; ++j)
		cin >> b[j];
	int bega, begb;
	for (int i = 0; i < n; ++i)
		if (a[i] == 0)
			bega = i;
	for (int i = 0; i < n; ++i)
		if (b[i] == 0)
			begb = i;
	for (int i = 0; i < bega; ++i)
		a[i + n] = a[i];
	for (int i = 0; i < begb; ++i)
		b[i + n] = b[i];
	for (int i = 1; i < n; ++i)
		a[i - 1] = a[i + bega];
	for (int i = 1; i < n; ++i)
		b[i - 1] = b[i + begb];
	--n;
	int delta;
	for (int i = 0; i < n; ++i)
		if (b[i] == a[0])
			delta = i;
	bool good = true;
	for (int i = 0; i < n; ++i)
		good &= (b[(i + delta) % n] == a[i]);
	if (good)
		cout << "YES";
	else
		cout << "NO";
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("sequence.in", "r", stdin);
	//freopen("sequence.out", "w", stdout);
#endif
	ios_base::sync_with_stdio(0), cin.tie(0);

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", (double)clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}

void debugOutput()
{}