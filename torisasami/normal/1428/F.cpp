#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb(x) push_back(x)
#define mp(a, b) make_pair(a, b)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define lscan(x) scanf("%I64d", &x)
#define lprint(x) printf("%I64d", x)
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define rep2(i, n) for (ll i = n - 1; i >= 0; i--)
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
	ll c = a % b;
	while (c != 0)
	{
		a = b;
		b = c;
		c = a % b;
	}
	return b;
}

long long extGCD(long long a, long long b, long long &x, long long &y)
{
	if (b == 0)
	{
		x = 1;
		y = 0;
		return a;
	}
	long long d = extGCD(b, a % b, y, x);
	y -= a / b * x;
	return d;
}

struct UnionFind
{
	vector<ll> data;

	UnionFind(int sz)
	{
		data.assign(sz, -1);
	}

	bool unite(int x, int y)
	{
		x = find(x), y = find(y);
		if (x == y)
			return (false);
		if (data[x] > data[y])
			swap(x, y);
		data[x] += data[y];
		data[y] = x;
		return (true);
	}

	int find(int k)
	{
		if (data[k] < 0)
			return (k);
		return (data[k] = find(data[k]));
	}

	ll size(int k)
	{
		return (-data[find(k)]);
	}
};

ll M = 1000000007;

vector<ll> fac(2000011);  //n!(mod M)
vector<ll> ifac(2000011); //k!^{M-2} (mod M)

ll mpow(ll x, ll n)
{
	ll ans = 1;
	while (n != 0)
	{
		if (n & 1)
			ans = ans * x % M;
		x = x * x % M;
		n = n >> 1;
	}
	return ans;
}
ll mpow2(ll x, ll n, ll mod)
{
	ll ans = 1;
	while (n != 0)
	{
		if (n & 1)
			ans = ans * x % mod;
		x = x * x % mod;
		n = n >> 1;
	}
	return ans;
}
void setcomb()
{
	fac[0] = 1;
	ifac[0] = 1;
	for (ll i = 0; i < 2000010; i++)
	{
		fac[i + 1] = fac[i] * (i + 1) % M; // n!(mod M)
	}
	ifac[2000010] = mpow(fac[2000010], M - 2);
	for (ll i = 2000010; i > 0; i--)
	{
		ifac[i - 1] = ifac[i] * i % M;
	}
}
ll comb(ll a, ll b)
{
	if (a == 0 && b == 0)
		return 1;
	if (a < b || a < 0)
		return 0;
	ll tmp = ifac[a - b] * ifac[b] % M;
	return tmp * fac[a] % M;
}
ll perm(ll a, ll b)
{
	if (a == 0 && b == 0)
		return 1;
	if (a < b || a < 0)
		return 0;
	return fac[a] * ifac[a - b] % M;
}
long long modinv(long long a)
{
	long long b = M, u = 1, v = 0;
	while (b)
	{
		long long t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= M;
	if (u < 0)
		u += M;
	return u;
}
ll modinv2(ll a, ll mod)
{
	ll b = mod, u = 1, v = 0;
	while (b)
	{
		ll t = a / b;
		a -= t * b;
		swap(a, b);
		u -= t * v;
		swap(u, v);
	}
	u %= mod;
	if (u < 0)
		u += mod;
	return u;
}

template <int mod>
struct ModInt
{
	int x;

	ModInt() : x(0) {}

	ModInt(int64_t y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

	ModInt &operator+=(const ModInt &p)
	{
		if ((x += p.x) >= mod)
			x -= mod;
		return *this;
	}

	ModInt &operator-=(const ModInt &p)
	{
		if ((x += mod - p.x) >= mod)
			x -= mod;
		return *this;
	}

	ModInt &operator*=(const ModInt &p)
	{
		x = (int)(1LL * x * p.x % mod);
		return *this;
	}

	ModInt &operator/=(const ModInt &p)
	{
		*this *= p.inverse();
		return *this;
	}

	ModInt operator-() const { return ModInt(-x); }

	ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }

	ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }

	ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }

	ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

	bool operator==(const ModInt &p) const { return x == p.x; }

	bool operator!=(const ModInt &p) const { return x != p.x; }

	ModInt inverse() const
	{
		int a = x, b = mod, u = 1, v = 0, t;
		while (b > 0)
		{
			t = a / b;
			swap(a -= t * b, b);
			swap(u -= t * v, v);
		}
		return ModInt(u);
	}

	ModInt pow(int64_t n) const
	{
		ModInt ret(1), mul(x);
		while (n > 0)
		{
			if (n & 1)
				ret *= mul;
			mul *= mul;
			n >>= 1;
		}
		return ret;
	}

	friend ostream &operator<<(ostream &os, const ModInt &p)
	{
		return os << p.x;
	}

	friend istream &operator>>(istream &is, ModInt &a)
	{
		int64_t t;
		is >> t;
		a = ModInt<mod>(t);
		return (is);
	}

	static int get_mod() { return mod; }
};

using mint = ModInt<mod>;

typedef vector<vector<mint>> Matrix;

Matrix mul(Matrix a, Matrix b)
{
	int i, j, k;
	mint t;
	int n = a.size(), m = b[0].size(), l = a[0].size();
	Matrix c(n, vector<mint>(m));
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < m; j++)
		{
			t = 0;
			for (k = 0; k < l; k++)
				t += a[i][k] * b[k][j];
			c[i][j] = t;
		}
	}
	return c;
}

Matrix mat_pow(Matrix x, ll n)
{
	ll k = x.size();
	Matrix ans(k, vector<mint>(k, 0));
	for (int i = 0; i < k; i++)
		ans[i][i] = 1;
	while (n != 0)
	{
		if (n & 1)
			ans = mul(ans, x);
		x = mul(x, x);
		n = n >> 1;
	}
	return ans;
}

ll calc(ll n){
	return n * (n + 1) / 2;
}

int main()
{
	ll n;
	cin >> n;
	string s;
	cin >> s;
	UnionFind uf(n);
	set<ll> se;
	se.insert(n);
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> t;
	rep(i, n){
		if(s[i]=='0'){
			if(i==0)
				se.insert(i);
			else if(s[i-1]!='0')
				se.insert(i);
			else
				uf.unite(i - 1, i);
		}
		else{
			if(i>0)
				if(s[i-1]=='1')
					uf.unite(i - 1, i);
		}
	}
	rep(i,n){
		if(s[i]=='1'){
			if(i==0)
				t.push(mp(uf.size(i), i));
			else if(s[i-1]!='1')
				t.push(mp(uf.size(i), i));
		}
	}
	ll b4 = 0;
	ll ans = 0;
	rep(l, n + 1){
		while(!t.empty()){
			auto q = t.top();
			t.pop();
			if (l == q.first){
				if(q.second > 0)
					uf.unite(q.second - 1, q.second);
				else
					se.insert(q.second);
				ll ne = *se.upper_bound(q.second);
				if(ne < n){
					uf.unite(q.second, ne);
					se.erase(ne);
				}
			}
			else{
				t.push(q);
				break;
			}
		}
		ll res = 0;
		queue<pair<ll, ll>> que;
		while(!t.empty()){
			auto q = t.top();
			t.pop();
			que.push(q);
			ll w = q.first;
			if(l > 0){
				res += w * l - calc(l - 1);
				if(q.second>0)
					res -= calc(l);
				if(*se.upper_bound(q.second)<n)
					res -= calc(l);
			}
		}
		while(!que.empty()){
			t.push(que.front());
			que.pop();
		}
		for (auto itr = se.begin(); itr != se.end();itr++){
			if(*itr == n)
				break;
			ll le = uf.size(*itr) + 2 * l;
			if(*itr==0)
				le -= l;
			if(*itr+uf.size(*itr)==n)
				le -= l;
			res += calc(le);
		}
		ans += (res - b4) * l;
		b4 = res;
	}
	cout << ans << endl;
}