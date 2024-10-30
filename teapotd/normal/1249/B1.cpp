#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

void solve() {
    int n; cin >> n;
    Vi perm(n);

    each(p, perm) {
        cin >> p;
        p--;
    }

    Vi ans(n, -1);

    rep(i, 0, n) {
        if (ans[i] != -1) continue;

        Vi cycle;
        int v = i;

        while (ans[v] == -1) {
            cycle.pb(v);
            ans[v] = -2;
            v = perm[v];
        }

        each(e, cycle) ans[e] = sz(cycle);
    }

    each(a, ans) cout << a << ' ';
    cout << '\n';
}

void run() {
    int q; cin >> q;
    while (q--) solve();
}