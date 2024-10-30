#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#ifdef LOC
#include "debuglib.h"
#else
#define deb(...)
#define DBP(...)
#endif
using namespace std;
using   ll         = long long;
using   Vi         = vector<int>;
using   Pii        = pair<int, int>;
#define pb           push_back
#define mp           make_pair
#define x            first
#define y            second
#define rep(i, b, e) for (int i = (b); i < (e); i++)
#define each(a, x)   for (auto& a : (x))
#define all(x)       (x).begin(), (x).end()
#define sz(x)        int((x).size())

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
void run();

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);
    run();
    return 0;
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        string s; cin >> s;

        vector<string> ans(n, string(n, '='));
        rep(i, 0, n) ans[i][i] = 'X';
        Vi tmp;

        rep(i, 0, n) {
            if (s[i] == '2') {
                tmp.pb(i);
            }
        }

        if (sz(tmp) == 1 || sz(tmp) == 2) {
            cout << "NO\n";
            continue;
        }

        rep(i, 0, sz(tmp)) {
            ans[tmp[i]][tmp[(i+1)%sz(tmp)]] = '+';
            ans[tmp[(i+1)%sz(tmp)]][tmp[i]] = '-';
        }

        cout << "YES\n";
        each(a, ans) cout << a << '\n';
    }
}