#include <bits/stdc++.h>
using namespace std;

#define nl "\n"
#define nf endl
#define ll long long
#define pb push_back
#define _ << ' ' <<

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
        cin >> a >> b >> n; k = 1;
        while (a % 2 == 0) {
            a /= 2; k *= 2;
        }
        while (b % 2 == 0) {
            b /= 2; k *= 2;
        }

        if (k >= n) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}