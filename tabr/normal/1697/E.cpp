#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0) {
        value = x % mod;
        if (value < 0) value += mod;
    }
    modular& operator+=(const modular& other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(const modular& other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(const modular& other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(const modular& other) {
        long long a = 0, b = 1, c = other.value, m = mod;
        while (c != 0) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0) a += mod;
        value = value * a % mod;
        return *this;
    }
    friend modular operator+(const modular& lhs, const modular& rhs) { return modular(lhs) += rhs; }
    friend modular operator-(const modular& lhs, const modular& rhs) { return modular(lhs) -= rhs; }
    friend modular operator*(const modular& lhs, const modular& rhs) { return modular(lhs) *= rhs; }
    friend modular operator/(const modular& lhs, const modular& rhs) { return modular(lhs) /= rhs; }
    modular& operator++() { return *this += 1; }
    modular& operator--() { return *this -= 1; }
    modular operator++(int) {
        modular res(*this);
        *this += 1;
        return res;
    }
    modular operator--(int) {
        modular res(*this);
        *this -= 1;
        return res;
    }
    modular operator-() const { return modular(-value); }
    bool operator==(const modular& rhs) const { return value == rhs.value; }
    bool operator!=(const modular& rhs) const { return value != rhs.value; }
    bool operator<(const modular& rhs) const { return value < rhs.value; }
};
template <long long mod>
string to_string(const modular<mod>& x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, const modular<mod>& x) {
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}

constexpr long long mod = 998244353;
using mint = modular<mod>;

mint power(mint a, long long n) {
    mint res = 1;
    while (n > 0) {
        if (n & 1) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}

vector<mint> fact(1, 1);
vector<mint> finv(1, 1);

mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    while ((int) fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int) fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    vector<vector<int>> d(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            d[i][j] = abs(x[i] - x[j]) + abs(y[i] - y[j]);
        }
    }
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        d[i][i] = (int) 1e9;
        int e = *min_element(d[i].begin(), d[i].end());
        for (int j = 0; j < n; j++) {
            if (d[i][j] == e || i == j) {
                g[i].emplace_back(j);
            }
        }
    }
    vector<int> a;
    vector<bool> done(n);
    for (int i = 0; i < n; i++) {
        if (done[i]) {
            continue;
        }
        bool ok = true;
        for (int j : g[i]) {
            if (g[i] != g[j]) {
                ok = false;
                break;
            }
        }
        if (ok) {
            a.emplace_back((int) g[i].size());
            for (int j : g[i]) {
                done[j] = true;
            }
        } else {
            a.emplace_back(1);
        }
    }
    debug(a);
    vector<mint> dp(n + 1);
    dp[0] = 1;
    for (int z : a) {
        vector<mint> new_dp(n + 1);
        for (int i = n - z; i >= 0; i--) {
            new_dp[i + z] += dp[i];
        }
        if (z != 1) {
            for (int i = n - 1; i >= 0; i--) {
                new_dp[i + 1] += dp[i];
            }
        }
        swap(dp, new_dp);
    }
    C(n, 0);
    mint ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += dp[i] * C(n, i) * fact[i];
    }
    cout << ans << '\n';
    return 0;
}