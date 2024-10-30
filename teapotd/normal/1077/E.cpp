#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

void run() {
    ll n; cin >> n;
    vector<ll> elems(n);
    each(e, elems) cin >> e;

    vector<ll> counts;
    ll last = -1;
    sort(all(elems));

    each(e, elems) {
        if (e != last) {
            counts.pb(0);
            last = e;
        }
        counts.back()++;
    }

    sort(all(counts), [](ll a, ll b) { return a > b; });

    ll ans = counts[0];
    ll len = 1, mult = counts[0];

    rep(i, 1, sz(counts)) {
        mult = min(mult/2, counts[i]);
        if (++len >= 20) break;
        ans = max(ans, mult * ((1<<len) - 1));
    }

    cout << ans << endl;
}