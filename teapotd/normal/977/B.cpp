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
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    string sAns;

    rep(i, 1, n) {
        string kek = s.substr(i-1, 2);
        int xd = 0;
        rep(j, 1, n) {
            if (s.substr(j-1, 2) == kek) xd++;
        }
        if (xd > ans) {
            ans = xd;
            sAns = kek;
        }
    }

    cout << sAns << endl;
}