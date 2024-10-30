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

ll i, i1, j, k, k1, t, n, m, res, flag[10], a, b, sa, sb;
vector<ll> va, vb;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    #if !ONLINE_JUDGE && !EVAL
        ifstream cin("input.txt");
        ofstream cout("output.txt");
    #endif

    cin >> t;
    while (t--) {
        cin >> a >> b; va.clear(); vb.clear();
        for (i = 0; i <= 30; i++) {
            if ((a >> i) & 1) va.pb(i);
            if ((b >> i) & 1) vb.pb(i);
        }

        sa = va.size(); sb = vb.size();
        if (sa < sb || a > b) {
            cout << "NO" << nl; continue;
        }

        flag[0] = 1;
        for (i = 0; i < sb; i++) {
            if (va[i] > vb[i]) flag[0] = 0;
        }

        if (flag[0] == 1) cout << "YES" << nl;
        else cout << "NO" << nl;
    }

    return 0;
}