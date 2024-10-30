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
    cout << fixed << setprecision(12);
    run();
    cout << flush; _Exit(0);
}

ll countInversions(vector<ll> perm) {
    ll ret = 0, cont = 1;
    Vi odd;
    while (cont) {
        odd.assign(sz(perm)+1, 0);
        cont = 0;
        rep(i, 0, sz(perm)) {
            if (perm[i] % 2) odd[perm[i]]++;
            else ret += odd[perm[i]+1];
            cont += perm[i] /= 2;
        }
    }
    return ret;
}

int compressVec(vector<ll*>& vec) {
    sort(all(vec), [](ll* l, ll* r) { return *l < *r; });
    vector<ll> old;
    each(e, vec) {
        if (old.empty() || old.back() != *e) old.pb(*e);
        *e = sz(old)-1;
    }
    return sz(old);
}

void run() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<ll> a(n);
        vector<ll*> tmp;
        rep(i, 0, n) {
            ll v; cin >> v;
            a[i] = (v << 30) - i;
            tmp.pb(&a[i]);
        }
        compressVec(tmp);
        cout << countInversions(a) << '\n';
    }
}