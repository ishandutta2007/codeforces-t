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

int M[305][305], W[305][305];

void run() {
    int t; cin >> t;

    while (t--) {
        int n, m; cin >> n >> m;
        bool ok = 1;

        rep(i, 0, n) rep(j, 0, m) {
            cin >> M[i][j];

            W[i][j] = 0;
            W[i][j] += i > 0;
            W[i][j] += j > 0;
            W[i][j] += i+1 < n;
            W[i][j] += j+1 < m;

            if (M[i][j] > W[i][j]) ok = 0;
        }

        if (ok) {
            cout << "YES\n";
            rep(i, 0, n) {
                rep(j, 0, m) {
                    cout << W[i][j] << ' ';
                }
                cout << '\n';
            }
        } else {
            cout << "NO\n";
        }
    }
}