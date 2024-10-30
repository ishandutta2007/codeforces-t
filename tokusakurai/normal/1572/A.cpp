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
const int MOD = 1000000007;
// const int MOD = 998244353;
const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}
template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<vector<int>> es(N);
        vector<int> deg(N, 0);

        rep(i, N) {
            int K;
            cin >> K;
            while (K--) {
                int u;
                cin >> u;
                u--;
                deg[i]++, es[u].eb(i);
            }
        }

        priority_queue<int, vector<int>, greater<int>> q1, q2;

        int ans = 0, s = 0;

        rep(i, N) {
            if (deg[i] == 0) q1.emplace(i), s++;
        }

        while (!empty(q1)) {
            ans++;
            while (!empty(q1)) {
                int i = q1.top();
                q1.pop();
                each(e, es[i]) {
                    if (--deg[e] == 0) {
                        s++;
                        if (e < i)
                            q2.emplace(e);
                        else
                            q1.emplace(e);
                    }
                }
            }
            while (!empty(q2)) {
                int i = q2.top();
                q2.pop();
                q1.emplace(i);
            }
        }

        cout << (s < N ? -1 : ans) << '\n';
    }
}