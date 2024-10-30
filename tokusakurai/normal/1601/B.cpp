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
    int N;
    cin >> N;

    vector<int> a(N + 1), b(N + 1);
    rep2(i, 1, N) cin >> a[i];
    rep2(i, 1, N) cin >> b[i];

    vector<vector<int>> es(N + 1);
    es[0].eb(0);
    rep2(i, 1, N) es[i + b[i]].eb(i);

    vector<vector<int>> ids(N + 1);
    rep2(i, 1, N) ids[i - a[i]].eb(i);

    queue<int> que;
    vector<int> d(N + 1, -1);
    d[0] = 0;
    que.emplace(0);

    int ptr = 0;
    vector<int> pre(N + 1, -1);

    while (!empty(que)) {
        int i = que.front();
        que.pop();
        each(e, es[i]) {
            while (ptr <= e) {
                each(u, ids[ptr]) {
                    d[u] = d[i] + 1;
                    pre[u] = e;
                    que.emplace(u);
                }
                ptr++;
            }
        }
    }
    // print(pre);

    cout << d[N] << '\n';

    vector<int> ans;
    ptr = N;

    while (pre[ptr] != -1) {
        int e = pre[ptr];
        ans.eb(pre[ptr]);
        ptr = e + b[e];
    }
    // reverse(all(ans));
    print(ans);
}