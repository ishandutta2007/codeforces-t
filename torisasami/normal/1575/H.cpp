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
    int N, M;
    cin >> N >> M;

    string S, T;
    cin >> S >> T;

    vector<vector<int>> p(M + 1, vector<int>(2, 0));

    rep2(i, 0, M) {
        rep(j, 2) {
            string X = T.substr(0, i) + char('0' + j);
            rep3(k, i + 1, 1) {
                if (k > M) continue;
                if (X.substr(i + 1 - k) == T.substr(0, k)) {
                    p[i][j] = k;
                    break;
                }
            }
        }
    }

    // rep(i, M + 1) print(p[i]);

    vector<vector<int>> dp(N - M + 2, vector<int>(M + 1, inf));
    vector<vector<int>> tmp(N - M + 2, vector<int>(M + 1, inf));
    dp[0][0] = 0;

    rep(i, N) {
        rep(j, N - M + 2) rep(k, M + 1) tmp[j][k] = inf;
        rep(j, N - M + 2) {
            rep(k, M + 1) {
                if (dp[j][k] == inf) continue;
                rep(l, 2) {
                    int nj = j, nk = p[k][l];
                    if (nk == M) nj++;
                    if (S[i] - '0' == l) {
                        chmin(tmp[nj][nk], dp[j][k]);
                    } else {
                        chmin(tmp[nj][nk], dp[j][k] + 1);
                    }
                }
            }
        }
        swap(dp, tmp);
    }

    rep2(i, 0, N - M + 1) {
        int x = *min_element(all(dp[i]));
        cout << (x == inf ? -1 : x) << (i == N - M + 1 ? '\n' : ' ');
    }
}