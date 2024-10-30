#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 110

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n; k = -1;
        for (i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                k = i; break;
            }
        }

        if (k == -1) cout << 1 << ' ' << n - 1 << nl;
        else cout << n / k << ' ' << n - (n / k) << nl;
    }

    return 0;
}