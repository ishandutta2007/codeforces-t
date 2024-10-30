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
    modular operator+(const modular& rhs) const { return modular(*this) += rhs; }
    modular operator-(const modular& rhs) const { return modular(*this) -= rhs; }
    modular operator*(const modular& rhs) const { return modular(*this) *= rhs; }
    modular operator/(const modular& rhs) const { return modular(*this) /= rhs; }
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

constexpr long long mod = 998244353LL;
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
    vector<int> a(n, -1);
    for (int i = 0; i < n; i++) {
        char c;
        cin >> c;
        if (c == '+') {
            cin >> a[i];
        }
    }
    mint ans = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1) {
            continue;
        }
        vector<mint> dp(1, 1);
        for (int j = 0; j < n; j++) {
            if (j < i) {
                if (a[j] == -1) {
                    dp[0] *= 2;
                    for (int k = 1; k < (int) dp.size(); k++) {
                        dp[k - 1] += dp[k];
                    }
                } else if (a[j] <= a[i]) {
                    dp.emplace_back(0);
                    for (int k = (int) dp.size() - 2; k >= 0; k--) {
                        dp[k + 1] += dp[k];
                    }
                } else {
                    for (auto& x : dp) {
                        x *= 2;
                    }
                }
            } else if (j == i) {
                continue;
            } else {
                if (a[j] == -1) {
                    for (int k = 1; k < (int) dp.size(); k++) {
                        dp[k - 1] += dp[k];
                    }
                } else if (a[j] < a[i]) {
                    dp.emplace_back(0);
                    for (int k = (int) dp.size() - 2; k >= 0; k--) {
                        dp[k + 1] += dp[k];
                    }
                } else {
                    for (auto& x : dp) {
                        x *= 2;
                    }
                }
            }
        }
        ans += accumulate(dp.begin(), dp.end(), mint(0)) * a[i];
    }
    cout << ans << '\n';
    return 0;
}