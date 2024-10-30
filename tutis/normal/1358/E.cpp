/*input
6
-2 -2 6
-1

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937_64 rng(0);
namespace {
template<typename A, typename B>
istream &operator>>( istream  &input, pair<A, B> &X ) {
	input >> X.first >> X.second;
	return input;
}
template<typename A, typename B>
ostream &operator<<( ostream &output, const pair<A, B> &X ) {
	output << X.first << " " << X.second;
	return output;
}
template<typename T>
istream &operator>>( istream  &input, vector<T> &X ) {
	for (T&i : X)
		input >> i;
	return input;
}
template<typename T>
ostream &operator<<( ostream &output, const vector<T> &X ) {
	for (ll t = 0; t < (ll)X.size(); t++)
	{
		if (t + 1 != (ll)X.size())
			cout << X[t] << " ";
		else
			cout << X[t];
	}
	return output;
}
}
namespace {
const ll mod = 998244353;
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	ll r = 1;
	while (y)
	{
		if (y % 2 == 1)
			r = (r * x) % mod;
		x = (x * x) % mod;
		y /= 2;
	}
	return r;
}
const ll maxsz = 30;
ll I[maxsz];
bool calc = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxsz)
	{
		if (!calc)
		{
			calc = true;
			I[1] = 1;
			I[0] = 0;
			for (ll i = 2; i < maxsz; ++i)
				I[i] = (mod - (mod / i) * I[mod % i] % mod) % mod;
		}
		return I[x];
	}
	return power(x, mod - 2);
}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	ll s[n + 1];
	s[0] = 0;
	ll x = 0;
	for (int i = 1; i <= n; i++)
	{
		if (i <= (n + 3) / 2)
		{
			cin >> x;
		}
		s[i] = s[i - 1] + x;
	}
	int lo = (n + 2) / 2;
	int hi = n;
	if (x < 0)
	{
		int mx = n;
		for (int i = 0; i < n; i++)
		{
			mx = min(mx, n - i);
			while (mx > 0 && s[i + mx] <= s[i])
				mx--;
			if (mx >= n - i && mx * 2 > n)
			{
				cout << mx << "\n";
				return 0;
			}
		}
	}
	for (int k : {n, n - 1, 1, n / 2, (n + 1) / 2, (n + 2) / 2, (n + 3) / 2})
	{
		bool ok = true;
		if (k <= 0 || k > n)
			ok = false;
		for (int i = k; i <= n; i++)
		{
			if (s[i] <= s[i - k])
			{
				ok = false;
			}
		}
		if (ok)
		{
			cout << k << "\n";
			return 0;
		}
	}
	cout << "-1\n";
}