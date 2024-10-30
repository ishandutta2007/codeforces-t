#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

#define INF (ll)1e18
#define mod 998244353
#define maxn 200010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b[maxn];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; flag[0] = 1; flag[1] = 0; b[1] = 0;
        for (i = 1; i <= n; i++) {
            cin >> a[i]; b[i] = a[i] - b[i];
            if (b[i] < 0) flag[0] = 0;
            if (b[i] <= 0) flag[1] = 1;
            if (b[i] > 0 && flag[1] == 1) flag[0] = 0;
            b[i + 1] = -b[i];
            // cout << b[i] << ' ';
        }
        // cout << nl;
        if (flag[0] == 1 && b[n + 1] == 0) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}