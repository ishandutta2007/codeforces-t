#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

template <long long mod>
struct modular {
    long long value;
    modular(long long x = 0LL) {
        value = x % mod;
        if (value < 0LL) value += mod;
    }
    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0LL) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
        long long a = 0LL, b = 1, c = other.value, m = mod;
        while (c != 0LL) {
            long long t = m / c;
            m -= t * c;
            swap(c, m);
            a -= t * b;
            swap(a, b);
        }
        a %= mod;
        if (a < 0LL) a += mod;
        value = value * a % mod;
        return *this;
    }
    modular operator-() { return modular(-value); }
    modular operator+(modular rhs) { return modular(*this) += rhs; }
    modular operator-(modular rhs) { return modular(*this) -= rhs; }
    modular operator*(modular rhs) { return modular(*this) *= rhs; }
    modular operator/(modular rhs) { return modular(*this) /= rhs; }
    bool operator==(modular rhs) { return value == rhs.value; }
    bool operator!=(modular rhs) { return value != rhs.value; }
    bool operator<(modular rhs) { return value < rhs.value; }
};
template <long long mod>
string to_string(modular<mod> x) {
    return to_string(x.value);
}
template <long long mod>
ostream& operator<<(ostream& stream, modular<mod> x) {
    x.value %= mod;
    if (x.value < 0LL) x.value += mod;
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0LL) x.value += mod;
    return stream;
};
const long long mod = 998244353LL;
using mint = modular<mod>;

inline mint pw(mint a, long long n) {
    mint res = 1;
    while (n > 0LL) {
        if (n & 1LL) {
            res *= a;
        }
        a *= a;
        n >>= 1;
    }
    return res;
}
vector<mint> fact, finv;
inline void cinit(int n) {
    fact.resize(n, mint(1));
    finv.resize(n, mint(1));
    for (int i = 2; i < n; i++) {
        fact[i] = fact[i - 1] * i;
    }
    finv[n - 1] /= fact[n - 1];
    for (int i = n - 2; i >= 2; i--) {
        finv[i] = finv[i + 1] * (i + 1);
    }
}
inline mint C(int n, int k) {
    if (n < k || k < 0 || n < 0) {
        return mint(0LL);
    }
    return fact[n] * finv[k] * finv[n - k];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<long long> c(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    sort(c.begin(), c.end());
    vector<long long> s = c;
    for (int i = 1; i < n; i++) {
        s[i] += s[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        mint res = 0;
        for (int j = n - 1 - i; j >= 0; j -= i) {
            res += s[j];
        }
        cout << res / n << " ";
    }
    cout << '\n';
    return 0;
}