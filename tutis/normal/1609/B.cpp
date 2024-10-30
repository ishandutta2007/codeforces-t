/*input
9 10
abcabcabc
1 a
1 b
2 c
3 a
4 b
5 c
8 a
9 b
1 c
4 a

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
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	string s;
	cin >> s;
	s = " " + s;
	int cnt = 0;
	for (int i = 3; i <= n; i++)
	{
		if (s[i] == 'c' && s[i - 1] == 'b' && s[i - 2] == 'a')
			cnt++;
	}
	while (q--)
	{
		int i;
		char c;
		cin >> i >> c;
		for (int id : {i + 2, i + 1, i})
		{
			if (id >= 3 && id <= n)
			{
				if (s[id] == 'c' && s[id - 1] == 'b' && s[id - 2] == 'a')
					cnt--;
			}
		}
		s[i] = c;
		for (int id : {i + 2, i + 1, i})
		{
			if (id >= 3 && id <= n)
			{
				if (s[id] == 'c' && s[id - 1] == 'b' && s[id - 2] == 'a')
					cnt++;
			}
		}
		cout << cnt << "\n";
	}
}