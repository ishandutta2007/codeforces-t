#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = (a); i <= (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)
#define PB push_back
#define ar2 array<int, 2>
typedef long long LL;
int P = 998244353;
const int INF = 1e9 + 1;
const int N = 2005;
mt19937 rng(time(0));

int T, n, x, a[N];

int main() {
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> T;
    while (T--) {
        cin >> n;
        rep(i, 1, n) cin >> a[i];
        int ans = a[n] - a[1];
        rep(i, 1, n - 1) ans = max(ans, a[i] - a[i + 1]);
        int x = 0;
        rep(i, 2, n) x = max(x, a[i]);
        ans = max(ans, x - a[1]);
        x = 999;
        rep(i, 1, n - 1) x = min(x, a[i]);
        ans = max(ans, a[n] - x);
        cout << ans << "\n";
    }
    return 0;
}