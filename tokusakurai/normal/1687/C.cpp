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

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N, M;
        cin >> N >> M;

        vector<ll> a(N), b(N);
        rep(i, N) cin >> a[i];
        rep(i, N) cin >> b[i];
        rep(i, N) a[i] -= b[i];

        vector<ll> s(N + 1, 0);
        rep(i, N) s[i + 1] = s[i] + a[i];

        vector<int> l(M), r(M);
        vector<vector<int>> idl(N + 1), idr(N + 1);
        vector<int> cnt(M, 2);
        queue<int> que;
        rep(i, M) {
            cin >> l[i] >> r[i];
            l[i]--;
            idl[l[i]].eb(i), idr[r[i]].eb(i);
            if (s[l[i]] == 0) cnt[i]--;
            if (s[r[i]] == 0) cnt[i]--;
            if (cnt[i] == 0) que.emplace(i);
        }

        if (s[N] != 0) {
            cout << "NO\n";
            continue;
        }

        set<int> rem;
        rep(i, N + 1) {
            if (s[i] != 0) rem.emplace(i);
        }

        while (!empty(que)) {
            int i = que.front();
            que.pop();
            int L = l[i], R = r[i];
            vector<int> tmp;

            for (auto it = rem.lower_bound(L); it != end(rem); it++) {
                int x = *it;
                if (x > R) break;
                each(e, idl[x]) {
                    if (--cnt[e] == 0) que.emplace(e);
                }
                each(e, idr[x]) {
                    if (--cnt[e] == 0) que.emplace(e);
                }
                tmp.eb(x);
            }

            each(e, tmp) rem.erase(e);
        }

        cout << (empty(rem) ? "YES\n" : "NO\n");
    }
}