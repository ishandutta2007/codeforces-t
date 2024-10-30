/*input
7
1 2
1 2
3 2
1 1 2 2 3 3
3 3
3 4 4 1 1 1 1 1 2
2 2
1 1 2 1
4 2
50 50 50 50 3 50 50 50
4 2
6 6 6 6 2 2 9 6
2 9
1 3 3 3 3 3 1 1 3 1 3 1 1 3 3 1 1 3

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
//using ull = __ull128_t;
using ull = unsigned long long;
using ll = long long;
using ld = double;
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename T>
void sort_unique(T &x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
//const ll mod = 998244353;
const ll mod = 1000000007;
ll power(ll a, ll b)
{
	if (abs(a) >= mod)
		a %= mod;
	if (abs(b) >= mod - 1)
		b %= (mod - 1);
	if (a < 0)
		a += mod;
	if (b < 0)
		b += mod - 1;
	ll r = 1;
	if (b % 2 == 1)
		r = a;
	b /= 2;
	while (b)
	{
		a = (a * a) % mod;
		if (b % 2 == 1)
			r = (r * a) % mod;
		b /= 2;
	}
	return r;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		int nm = n * m;
		pair<int, int> a[nm];
		for (int i = 0; i < nm; i++) {
			cin >> a[i].first;
			a[i].second = i;
		}
		sort(a, a + (n * m));
		for (int i = 0; i < n; i++)
		{
			sort(a + i * m, a + i * m + m, [&](pair<int, int>a, pair<int, int>b) {
				if (a.first != b.first)
					return a.first < b.first;
				else
					return a.second > b.second;
			});
		}
		int pos[n * m];
		for (int i = 0; i < nm; i++)
			pos[a[i].second] = i;
		ll ans = 0;
		ordered_set<int>x[n];
		for (int i = 0; i < nm; i++)
		{
			ans += x[pos[i] / m].order_of_key(pos[i] % m);
			x[pos[i] / m].insert(pos[i] % m);
		}
		cout << ans << "\n";
	}
}