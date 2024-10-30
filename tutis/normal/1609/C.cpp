/*input
6
7 3
10 2 1 3 1 19 3
3 2
1 13 1
9 3
2 4 2 1 1 1 1 4 2
3 1
1 1 1
4 1
1 2 1 1
2 2
1 2

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
mt19937_64 rng(0);
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
	vector<bool>prime(1000001, true);
	for (int i = 2; i < 1000001; i++)
	{
		if (prime[i])
		{
			for (int j = 2 * i; j < 1000001; j += i)
				prime[j] = false;
		}
	}
	prime[1] = false;
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n, e;
		cin >> n >> e;
		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];
		ll ans = 0;
		for (int i = 0; i < e; i++)
		{
			ll cnt1 = 0;
			ll cntp = 0;
			ll cnt2 = 0;
			for (int j = i; j < n; j += e)
			{
				if (a[j] == 1)
				{
					cnt2++;
					ans += (cnt1 + 1) * cntp;
				}
				else if (prime[a[j]])
				{
					cnt1 = cnt2;
					cntp = 1;
					cnt2 = 0;
					ans += cnt1;
				}
				else
				{
					cnt1 = cnt2 = cntp = 0;
				}
				//cout << a[j] << " " << cnt1 << " " << cnt2 << endl;
			}
			// cout << ans << endl;
			// cout << endl;
		}
		cout << ans << "\n";
	}
}