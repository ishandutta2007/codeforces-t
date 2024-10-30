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

vector<Vi> G;
Vi type; // 0 = "leaf", 1 = "bud root"
int ans;

void dfs(int v, int p) {
    int leafs = 0;
    each(e, G[v]) if (e != p) {
        dfs(e, v);
        leafs += (type[e] == 0);
    }
    type[v] = (leafs > 0);

    if (type[v] == 1) {
        ans += leafs - 1;
    }
}

void run() {
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        G.assign(n, {});

        rep(i, 1, n) {
            int u, v; cin >> u >> v;
            G[u-1].pb(v-1);
            G[v-1].pb(u-1);
        }

        ans = 1;
        type.assign(n, -1);
        dfs(0, -1);
        cout << ans << '\n';
    }
}