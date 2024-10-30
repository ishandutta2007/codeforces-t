#include <bits/stdc++.h>
using namespace std;

int M;
struct modint {
    modint() : n(0) {}
    template <class T> modint(T n) { n %= M; if (n < 0) n += M; this->n = n; }

    modint & operator+=(const modint &r) { n += r.n; if (n >= M) n -= M; return *this; }
    modint & operator-=(const modint &r) { n -= r.n; if (n < 0) n += M; return *this; }
    modint & operator*=(const modint &r) { n = ((long long) n * r.n % M); return *this; }

    modint & operator--() { if (--n == -1) n = M - 1; return *this; }
    modint & operator++() { if (++n == M) n = 0; return *this; }
    modint operator--(int) { modint t = *this; --*this; return t; }
    modint operator++(int) { modint t = *this; ++*this; return t; }

    modint operator-() const { return 0 - *this; }
    modint operator+() const { return *this; }

    modint pow(long long k = M - 2) const {
        modint f = 1, p = *this;
        while (k > 0) {
            if (k % 2 == 1) f *= p;
            p *= p, k /= 2;
        }
        return f;
    }

    int mod() const { return M; }

    friend modint operator+(modint l, const modint &r) { return l += r; }
    friend modint operator-(modint l, const modint &r) { return l -= r; }
    friend modint operator*(modint l, const modint &r) { return l *= r; }
    
    friend bool operator==(const modint &l, const modint &r) { return l.n == r.n; }
    friend bool operator!=(const modint &l, const modint &r) { return l.n != r.n; }

    friend ostream & operator<<(ostream &out, const modint &r) { return out << r.n; }

    int n;
};

using mint = modint;

const int N = 2e3 + 1;

vector<int> adj[N];
mint ways[N][N];
int n;

void dfs(int u) {
	for (auto c : adj[u]) {
		adj[c].erase(find(adj[c].begin(), adj[c].end(), u));
		dfs(c);
	}

	int deg = adj[u].size();
	vector prefix(n, vector<mint>(deg + 1)), suffix(n, vector<mint>(deg + 1));
	for (int i = 0; i < n; ++i) {
		prefix[i][0] = suffix[i][deg] = 1;
		for (int j = 0; j < deg; ++j) {
			prefix[i][j + 1] = ways[adj[u][j]][i] * prefix[i][j];
		}
		for (int j = deg - 1; j >= 0; --j) {
			suffix[i][j] = ways[adj[u][j]][i] * suffix[i][j + 1];
		}
	}

	mint sum = 0;
	for (int len = 0; len < n; ++len) {
		ways[u][len] -= deg * sum;
		sum += prefix[len][deg];
		ways[u][len] += sum;
	}

	for (int i = 0; i < deg; ++i) {
		sum = 0;
		for (int len = 0; len < n; ++len) {
			ways[u][len] += ways[adj[u][i]][len] * sum;
			sum += prefix[len][i] * suffix[len][i + 1];
		}
	}
}

mint fact[N], inv[N];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

	cin >> n >> M;

	fact[0] = inv[0] = 1;
	for (int i = 1; i < N; ++i) {
		fact[i] = i * fact[i - 1];
		inv[i] = fact[i].pow();
	}

	for (int i = 0; i < n - 1; ++i) {
		int u, v; cin >> u >> v; --u, --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(0);

	vector<mint> answer(n, 1);
	for (int i = 0; i < n - 1; ++i) {
		for (auto c : adj[0]) {
			answer[i] *= ways[c][i];
		}

		for (int j = 0; j < i; ++j) {
			answer[i] -= answer[j] * fact[i + 1] * inv[i - j] * inv[j + 1];
		}

		cout << answer[i] << " ";
	}

	cout << "\n";
}