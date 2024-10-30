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
    string S;
    cin >> S;

    int N = sz(S);

    if (N == 1) {
        if (S[0] == '0' || S[0] == '_' || S[0] == 'X') {
            cout << "1\n";
        } else {
            cout << "0\n";
        }
        return 0;
    }

    vector<string> X = {"00", "25", "50", "75"};

    ll ans = 0;

    each(e, X) {
        if (N == 2 && e == "00") continue;
        int id = -1;
        if (S[N - 1] == 'X') {
            id = e[1] - '0';
        } else if (S[N - 1] != '_' && S[N - 1] != e[1]) {
            continue;
        }

        if (S[N - 2] == 'X') {
            int tmp = e[0] - '0';
            if (id != -1 && id != tmp) {
                continue;
            } else {
                id = tmp;
            }
        } else if (S[N - 2] != '_' && S[N - 2] != e[0]) {
            continue;
        }

        if (N == 2) {
            ans++;
            continue;
        }

        ll x = 1;

        if (S[0] == '0') {
            continue;
        } else if (S[0] == '_') {
            x *= 9;
        } else if (S[0] == 'X') {
            if (id == 0) {
                continue;
            } else if (id == -1) {
                id = 1;
                x *= 9;
            }
        }

        rep2(j, 1, N - 3) {
            if (S[j] == '_') {
                x *= 10;
            } else if (S[j] == 'X') {
                if (id == -1) {
                    id = 1;
                    x *= 10;
                }
            }
        }

        ans += x;
    }

    cout << ans << '\n';
}