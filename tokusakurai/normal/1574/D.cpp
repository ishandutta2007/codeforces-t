#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty()) cout << '\n';
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

struct Random_Number_Generator {
    mt19937_64 mt;

    Random_Number_Generator() : mt(chrono::steady_clock::now().time_since_epoch().count()) {}

    int64_t operator()(int64_t l, int64_t r) {
        uniform_int_distribution<int64_t> dist(l, r - 1);
        return dist(mt);
    }

    int64_t operator()(int64_t r) { return (*this)(0, r); }
} rng;

using ull = unsigned long long;

struct Rolling_Hash {
    const ull mod = (1ULL << 61) - 1;

    ull calc_mod(ull x) const {
        ull ret = (x >> 61) + (x & mod);
        return ret - (ret >= mod ? mod : 0);
    }

    ull mul(ull x, ull y) const {
        x = calc_mod(x), y = calc_mod(y);
        ull x1 = x >> 31, x2 = x & ((1ULL << 31) - 1), y1 = y >> 31, y2 = y & ((1ULL << 31) - 1);
        ull z = x1 * y2 + x2 * y1, z1 = z >> 30, z2 = z & ((1ULL << 30) - 1);
        return calc_mod(x1 * y1 * 2 + x2 * y2 + z1 + (z2 << 31));
    }

    ull pow(ull x, ull n) const {
        ull ret = 1;
        for (; n > 0; n >>= 1, x = mul(x, x)) {
            if (n & 1) ret = mul(ret, x);
        }
        return ret;
    }

    ull base; // 
    vector<ull> hashed, pw;

    void set_base() { // 
        Random_Number_Generator rng;
        while (true) {
            ull k = rng(mod);
            if (gcd(mod - 1, k) != 1) continue;
            base = pow(3, k);
            if (base < 256) continue;
            break;
        }
    }

    Rolling_Hash(const string &s) {
        set_base();
        int n = s.size();
        hashed.resize(n + 1), pw.resize(n + 1);
        hashed[0] = 0, pw[0] = 1;
        for (int i = 0; i < n; i++) {
            pw[i + 1] = mul(pw[i], base);
            hashed[i + 1] = mul(hashed[i], base) + s[i];
            if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
        }
    }

    ull query(int l, int r) const { //  [l,r) 
        ull ret = hashed[r] + mod - mul(hashed[l], pw[r - l]);
        return ret - (ret >= mod ? mod : 0);
    }

    ull get_hash(const string &s) const {
        ull ret = 0;
        for (int i = 0; i < (int)s.size(); i++) {
            ret = mul(ret, base) + s[i];
            if (ret >= mod) ret -= mod;
        }
        return ret;
    }
};

template <typename T>
struct Array_Hash {
    const ull mod = (1ULL << 61) - 1;

    ull calc_mod(ull x) const {
        ull ret = (x >> 61) + (x & mod);
        return ret - (ret >= mod ? mod : 0);
    }

    ull mul(ull x, ull y) const {
        x = calc_mod(x), y = calc_mod(y);
        ull x1 = x >> 31, x2 = x & ((1ULL << 31) - 1), y1 = y >> 31, y2 = y & ((1ULL << 31) - 1);
        ull z = x1 * y2 + x2 * y1, z1 = z >> 30, z2 = z & ((1ULL << 30) - 1);
        return calc_mod(x1 * y1 * 2 + x2 * y2 + z1 + (z2 << 31));
    }

    ull pow(ull x, ull n) const {
        ull ret = 1;
        for (; n > 0; n >>= 1, x = mul(x, x)) {
            if (n & 1) ret = mul(ret, x);
        }
        return ret;
    }

    ull base;
    vector<ull> pw;

    void set_base(T m) {
        while (true) {
            ull k = rng(mod);
            if (gcd(mod - 1, k) != 1) continue;
            base = pow(3, k);
            if (base <= ull(m)) continue;
            break;
        }
    }

    Array_Hash(int n, T m) { // 
        set_base(m);
        pw.resize(n + 1);
        pw[0] = 1;
        for (int i = 0; i < n; i++) { pw[i + 1] = mul(pw[i], base); }
    }

    ull get_hash(const vector<T> &v) const {
        ull ret = 0;
        for (int i = 0; i < (int)v.size(); i++) {
            ret += mul(v[i], pw[i]);
            if (ret >= mod) ret -= mod;
        }
        return ret;
    }
};

int main() {
    int N;
    cin >> N;

    vector<vector<int>> a(N);
    vector<int> c(N);
    int S = 0;

    rep(i, N) {
        cin >> c[i];
        a[i].resize(c[i]);
        rep(j, c[i]) cin >> a[i][j];
        S += a[i].back();
    }

    Array_Hash<int> ah(N, 200000);

    set<ull> ng;
    int M;
    cin >> M;
    rep(i, M) {
        vector<int> b(N);
        rep(i, N) {
            cin >> b[i];
            b[i]--;
        }
        ng.emplace(ah.get_hash(b));
    }

    map<ull, vector<int>> mp;
    map<ull, int> d;
    using P = pair<int, ull>;
    priority_queue<P, vector<P>, greater<P>> que;
    vector<int> b = c;
    each(e, b) e--;
    ull s = ah.get_hash(b);
    que.emplace(0, s);
    mp[s] = b, d[s] = 0;

    while (!empty(que)) {
        auto [t, x] = que.top();
        que.pop();
        vector<int> v = mp[x];
        if (!ng.count(x)) {
            print(v, 1);
            return 0;
        }
        if (d[x] < t) continue;

        rep(i, N) {
            if (v[i] > 0) {
                int nt = t + (a[i][v[i]] - a[i][v[i] - 1]);
                v[i]--;
                ull nx = ah.get_hash(v);
                if (!d.count(nx) || d[nx] > nt) {
                    d[nx] = nt;
                    mp[nx] = v;
                    que.emplace(nt, nx);
                }
                v[i]++;
            }
        }
    }
}