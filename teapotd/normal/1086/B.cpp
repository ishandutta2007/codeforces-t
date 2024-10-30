#include<bits/stdc++.h>/////////////////////////////////////////
#define deb(...)////////////////////////////////////////////////
#define DBP(...)////////////////////////////////////////////////
#ifdef LOC//////////////////////////////////////////////////////
#include"debuglib.h"////////////////////////////////////////////
#endif//////////////////////////////////////////////////////////
#define x first/////////////////////////////////////////////////
#define y second////////////////////////////////////////////////
#define pb push_back////////////////////////////////////////////
#define sz(x)int((x).size())////////////////////////////////////
#define each(a,x)for(auto&a:(x))////////////////////////////////
#define all(x)(x).begin(),(x).end()/////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)//////////////////////
using namespace std;using ll=int64_t;using Pii=pair<int,int>;///
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio//
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}///
//------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

void run() {
    int n, s; cin >> n >> s;
    vector<Vi> G(n);

    rep(i, 1, n) {
        int a, b; cin >> a >> b;
        G[a-1].pb(b-1);
        G[b-1].pb(a-1);
    }

    if (n == 2) {
        cout << s << endl;
        return;
    }

    int leaves = 0;
    each(v, G) leaves += (sz(v) == 1);
    cout << (double(s) / double(leaves) * 2) << endl;
}