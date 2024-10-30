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
#pragma comment(linker, "/STACK:167772160")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef pair<int, int> pii;
typedef vector<int>::iterator vint_iter;

const int INF = 1e9 + 10;
const ll LINF = ll(2e18) + 10;
const ld PI = acosl(-1);
const double eps = 1e-8;
const ld EPS = 1e-13;

#pragma endregion

const int N = 1e5 + 10;
int sz[N];
vector<int> edges[N];
double ans[N];
int n;

void dfs_sz(int v)
{
	sz[v] = 1;
	for (auto e : edges[v])
	{
		dfs_sz(e);
		sz[v] += sz[e];
	}
}

void dfs_ans(int v, double p)
{
	ans[v] = p;
	for(auto e : edges[v])
	{
		int s = sz[v] + 1 - sz[e];
		dfs_ans(e, p + s / 2.0);
	}
}

void solve()
{
	scanf("%d", &n);
	for (int i = 1; i < n; ++i)
	{
		int p;
		scanf("%d", &p);
		--p;
		edges[p].push_back(i);
	}
	dfs_sz(0);
	dfs_ans(0, 1);
	for (int i = 0; i < n; ++i)
		printf("%.9lf ", ans[i]);
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("bandits.in", "r", stdin);
	//freopen("bandits.out", "w", stdout);
#endif

	solve();

#ifdef LOCAL
	fprintf(stderr, "\n\nTime: %.3f", double(clock()) / CLOCKS_PER_SEC);
#endif
}