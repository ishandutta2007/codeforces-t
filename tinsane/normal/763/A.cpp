#pragma region Template
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
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
#include <unordered_map>
#include <unordered_set>
#include <random>
#include <complex>
#pragma comment(linker, "/STACK:167772160")

using namespace std;
#define mp make_pair
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#define print_var(x) cerr << #x << " : " << (x) << endl
#define print_array(arr, len) {cerr << #arr << " : "; for(int i = 0; i < len; ++i) cerr << arr[i] << ' '; cerr << endl;}
#define print_2d_array(arr, len1, len2) {cerr << #arr << endl; for(int i = 0; i < len1; ++i, cerr << endl) for(int j = 0; j < len2; ++j) cerr << arr[i][j] << ' ';}
#define print_iterable(i) {cerr << #i << " : "; for(auto e : i) cerr << e << ' '; cerr << endl;}
#define print_new_line() cerr << endl
#else
#define eprintf(...) (void)0
#define print_var(x) (void)0
#define print_array(arr, len) {}
#define print_2d_array(arr, len1, len2) {}
#define print_iterable(i) {}
#define print_new_line() (void)0
#endif

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int, int> pii;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const double PI = acosl(-1);
const double eps = 1e-7;
const ld EPS = 1e-11;

#pragma endregion

const int N = 1e5 + 10;
int n;
vector<int >edges[N];
int c[N];
int cons[N];
set<int> diff;

void solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n - 1; ++i)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		--a, --b;
		edges[a].push_back(b);
		edges[b].push_back(a);
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &c[i]);
		diff.insert(c[i]);
	}
	if (diff.size() == 1)
	{
		puts("YES\n1");
		return;
	}
	for (int i = 0; i < n; ++i)
	{
		bool ok = true;
		for (auto e : edges[i])
			if (c[e] != c[i])
				ok = false;
		if (!ok)
			++cons[c[i]];
	}
	int col = -1;
	for (int i = 0; i < N; ++i)
		if (cons[i] == 1)
		{
			col = i;
			break;
		}
	if (col == -1)
	{
		puts("NO");
		return;
	}
	int root = -1;
	for (int i = 0; i < n; ++i)
	{
		if (c[i] != col)
			continue;
		for (auto e : edges[i])
			if (c[e] != col)
				root = i;
	}
	bool ok = true;
	for (int i = 0; i < n; ++i)
	{
		if (i == root)
			continue;
		for (auto e : edges[i])
			if (c[e] != c[i] && e != root)
				ok = false;
	}
	if (ok)
	{
		puts("YES");
		printf("%d\n", root + 1);
		return;
	}
	for (auto e : edges[root])
		if (c[e] != c[root])
		{
			root = e;
			break;
		}
	ok = true;
	for (int i = 0; i < n; ++i)
	{
		if (i == root)
			continue;
		for (auto e : edges[i])
			if (c[e] != c[i] && e != root)
				ok = false;
	}
	if (ok)
	{
		puts("YES");
		printf("%d\n", root + 1);
		return;
	}
	puts("NO");
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#ifdef NOERR
	freopen("err.txt", "w", stderr);
#endif
#else
	//freopen("alter.in", "r", stdin);
	//freopen("alter.out", "w", stdout);
#endif

#ifdef ST
	while (true)
		solve();
#endif
#ifdef CASES
#define MULTITEST
#endif
#ifdef MULTITEST
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; ++i)
	{
#ifdef CASES
		printf("Case #%d: ", i + 1);
#endif
		solve();
#ifdef CASES
		//eprintf("Passed case #%d:\n", i + 1);
#endif
	}
#else
		solve();
#endif

	eprintf("\n\nTime: %.3lf", double(clock()) / CLOCKS_PER_SEC);
}