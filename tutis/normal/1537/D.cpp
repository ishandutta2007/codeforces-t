/*input
4
1
4
12
69

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
void sort_unique(T x) {sort(x.begin(), x.end()); x.erase(unique(x.begin(), x.end()), x.end());}
const ll mod = 998244353;
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
// 	bool laimi[1000];
// 	laimi[1]=false;
// 	for(int i=2;)
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		bool laimi;
		if (n % 2 == 0)
		{
			laimi = true;
			if ((n == ((n & -n))))
			{
				int k = 0;
				while (n % 2 == 0)
				{
					n /= 2;
					k++;
				}
				if (k % 2 == 0)
					laimi = true;
				else
					laimi = false;
			}
		}
		else
		{
			laimi = false;
		}
		if (laimi)
			cout << "Alice\n";
		else
			cout << "Bob\n";
	}
}