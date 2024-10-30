#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back

#define INF (ll)1e18
#define mod 998244353
#define maxn 100010

ll i, i1, j, k, k1, t, n, m, res, flag[10], a[maxn], b;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> n;
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }

        sort(a, a + n);
        res = -INF;
        for (i = 0; i <= 5; i++) {
            k = 1;
            for (j = 0; j < i; j++) k *= a[j];
            for (j = n - (5 - i); j < n; j++) k *= a[j];
            res = max(res, k);
        }

        cout << res << nl;
    }

    return 0;
}