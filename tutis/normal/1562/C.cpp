/*input
7
6
101111
9
111000111
8
10000000
5
11011
6
001111
3
101
30
100000000000000100000000000000
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
		int n;
		cin >> n;
		string s;
		cin >> s;
		int cnt = 0;
		while (cnt < n && s[n - cnt - 1] == '1')
			cnt++;
		if (cnt - 1 >= n / 2)
		{
			cout << n - cnt + 1 << " " << n - 1 << " ";
			cout << n - cnt + 2 << " " << n << "\n";
			goto X;
		}
		for (int i = 1; i < n; i++)
		{
			if (s[i] == '0' && (i - 1) - 0 + 1 >= n / 2)
			{
				cout << 1 << " " << i + 1 << " ";
				cout << 1 << " " << i << "\n";
				goto X;
			}
		}
		cout << n / 2 << " " << n << " " << n / 2 + 1 << " " << n << "\n";
X:;
	}
}