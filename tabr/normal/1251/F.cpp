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
    modular& operator+=(modular other) {
        if ((value += other.value) >= mod) value -= mod;
        return *this;
    }
    modular& operator-=(modular other) {
        if ((value -= other.value) < 0) value += mod;
        return *this;
    }
    modular& operator*=(modular other) {
        value = value * other.value % mod;
        return *this;
    }
    modular& operator/=(modular other) {
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
    if (x.value < 0) x.value += mod;
    return stream << x.value;
}
template <long long mod>
istream& operator>>(istream& stream, modular<mod>& x) {
    stream >> x.value;
    x.value %= mod;
    if (x.value < 0) x.value += mod;
    return stream;
}
const long long mod = 998244353LL;
using mint = modular<mod>;

inline mint pw(mint a, long long n) {
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
vector<mint> fact(1, 1), finv(1, 1);
inline mint C(int n, int k) {
    if (n < k || k < 0) {
        return mint(0);
    }
    if (n >= mod) {
        mint res = 1;
        while (n) {
            res *= C(n % (int)mod, k % (int)mod);
            n /= (int)mod;
            k /= (int)mod;
        }
        return res;
    }
    while ((int)fact.size() < n + 1) {
        fact.emplace_back(fact.back() * (int)fact.size());
        finv.emplace_back(mint(1) / fact.back());
    }
    return fact[n] * finv[k] * finv[n - k];
}

mint root;
int base;
int max_base;
vector<mint> roots;
vector<int> rev;

void ensure_base(int nbase) {
    if (roots.empty()) {
        auto tmp = mod - 1;
        max_base = 0;
        while (tmp % 2 == 0) {
            tmp /= 2;
            max_base++;
        }
        root = 2;
        while (pw(root, (mod - 1) >> 1) == 1) {
            root += 1;
        }
        root = pw(root, (mod - 1) >> max_base);
        base = 1;
        rev = {0, 1};
        roots = {0, 1};
    }
    if (nbase <= base) {
        return;
    }
    rev.resize(1 << nbase);
    for (int i = 0; i < (1 << nbase); i++) {
        rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
    }
    roots.resize(1 << nbase);
    while (base < nbase) {
        mint z = pw(root, 1 << (max_base - 1 - base));
        for (int i = 1 << (base - 1); i < (1 << base); i++) {
            roots[i << 1] = roots[i];
            roots[(i << 1) + 1] = roots[i] * z;
        }
        base++;
    }
}

void ntt(vector<mint>& a) {
    int n = (int)a.size();
    int zeros = __builtin_ctz(n);
    ensure_base(zeros);
    int shift = base - zeros;
    for (int i = 0; i < n; i++) {
        if (i < (rev[i] >> shift)) {
            swap(a[i], a[rev[i] >> shift]);
        }
    }
    for (int k = 1; k < n; k <<= 1) {
        for (int i = 0; i < n; i += 2 * k) {
            for (int j = 0; j < k; j++) {
                mint x = a[i + j];
                mint y = a[i + j + k] * roots[j + k];
                a[i + j] = x + y;
                a[i + j + k] = x - y;
            }
        }
    }
}

vector<mint> multiply(vector<mint> a, vector<mint> b) {
    int need = (int)a.size() + (int)b.size() - 1;
    int nbase = 0;
    while ((1 << nbase) < need) {
        nbase++;
    }
    ensure_base(nbase);
    int sz = 1 << nbase;
    a.resize(sz);
    b.resize(sz);
    ntt(a);
    ntt(b);
    mint inv = mint(1) / mint(sz);
    for (int i = 0; i < sz; i++) {
        a[i] *= b[i] * inv;
    }
    reverse(a.begin() + 1, a.end());
    ntt(a);
    a.resize(need);
    return a;
}

vector<mint>& operator*=(vector<mint>& a, const vector<mint>& b) {
    if (min(a.size(), b.size()) < 150) {
        vector<mint> c = a;
        a.assign(a.size() + b.size() - 1, 0);
        for (int i = 0; i < (int)c.size(); i++) {
            for (int j = 0; j < (int)b.size(); j++) {
                a[i + j] += c[i] * b[j];
            }
        }
    } else {
        a = multiply(a, b);
    }
    return a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(k);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < k; i++) {
        cin >> b[i];
    }
    int tt;
    cin >> tt;
    vector<int> q(tt);
    for (int i = 0; i < tt; i++) {
        cin >> q[i];
        q[i] /= 2;
        q[i]--;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    vector<int> s(k), t(k);
    for (int i = 0; i < n; i++) {
        int j = i;
        while (j != n && a[i] == a[j]) {
            j++;
        }
        if (j - i == 1) {
            for (int l = 0; l < k; l++) {
                if (b[l] > a[i]) {
                    s[l]++;
                }
            }
        } else {
            for (int l = 0; l < k; l++) {
                if (b[l] > a[i]) {
                    t[l]++;
                }
            }
        }
        i = j - 1;
    }
    vector<mint> ans(tt);
    for (int l = 0; l < k; l++) {
        vector<mint> x(1, 1);
        vector<mint> y(2, 1);
        y[1] = 2;
        while (s[l]) {
            if (s[l] & 1) {
                x *= y;
            }
            s[l] /= 2;
            y = multiply(y, y);
        }
        y = vector<mint>(2, 1);
        t[l] *= 2;
        while (t[l]) {
            if (t[l] & 1) {
                x *= y;
            }
            t[l] /= 2;
            y = multiply(y, y);
        }
        for (int i = 0; i < tt; i++) {
            if (q[i] - b[l] < 0 || q[i] - b[l] >= (int)x.size()) {
                continue;
            }
            ans[i] += x[q[i] - b[l]];
        }
    }
    for (int i = 0; i < tt; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}