/*input
3
2 3 4
2 2
2 3 4
3 2
2 4 3
3 2
*/
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using ordered_map = tree<T, X, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename X>
using fast_map = cc_hash_table<T, X>;
//using ull = __uint128_t;
using ull = unsigned long long;
using ll = long long;
using ld = long double;
mt19937_64 rng(123);
template<typename T>
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, u, v;
		cin >> n >> u >> v;
		int a[n + 1];
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		bool tvo = true;
		for (int i = 2; i <= n; i++)
			tvo &= abs(a[i] - a[i - 1]) <= 1;
		if (tvo)
		{
			bool same = true;
			for (int i = 2; i <= n; i++)
				same &= a[i] == a[i - 1];
			if (same)
			{
				cout << min(2 * v, v + u) << "\n";
			}
			else
			{
				cout << min(u, v) << "\n";
			}
		}
		else
		{
			cout << "0\n";
		}
	}
}