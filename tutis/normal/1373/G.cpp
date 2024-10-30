/*input
5 3 5
4 4
3 5
2 4
3 4
3 5
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
mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
const ll mod = 998244353;
const ll maxinv = 30;
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
ll power(ll x, ll y)
{
	x %= mod;
	if (x < 0)
		x += mod;
	y %= (mod - 1);
	if (y < 0)
		y += mod - 1;
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
ll I___[maxinv];
bool calc___ = false;
ll inv(ll x)
{
	if (x >= 0 && x < maxinv)
	{
		if (!calc___)
		{
			assert(maxinv <= mod);
			calc___ = true;
			I___[1] = 1;
			I___[0] = 0;
			for (ll i = 2; i < maxinv; ++i)
			{
				I___[i] = -(mod / i) * I___[mod % i];
				I___[i] %= mod;
				if (I___[i] < 0)
					I___[i] += mod;
			}
		}
		return I___[x];
	}
	return power(x, mod - 2);
}
}
struct ST
{
	int kiek = 0;
	int mx = 0;
	int l, r;
	ST*left, *right;
	ST(int l, int r): l(l), r(r)
	{
		if (l < r)
		{
			left = new ST(l, (l + r) / 2);
			right = new ST((l + r) / 2 + 1, r);
		}
	}
	void add(int p, int del)
	{
		kiek += del;
		if (l < r)
		{
			if (p <= (l + r) / 2)
				left->add(p, del);
			else
				right->add(p, del);
			mx = max(left->mx, right->mx - left->kiek);
		}
		else
		{
			if (kiek == 0)
				mx = -1e8;
			else
				mx = l;
		}
	}
} medis(0, 400005);
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	set<pair<int, int>>S;
	while (m--)
	{
		int x, y;
		cin >> x >> y;
		int p = y + abs(x - k);
		if (S.count({x, y}))
		{
			S.erase({x, y});
			//cout << "-" << p << "\n";
			medis.add(p, -1);
		}
		else
		{
			S.insert({x, y});
			//cout << "+" << p << "\n";
			medis.add(p, 1);
		}
		int v = medis.mx;
		cout << max(0, medis.mx + medis.kiek - n - 1) << "\n";
	}
	return 0;
}