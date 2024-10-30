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

struct Entry {
    int count{0};
    string str = "-";
};

ll encode(string s) {
    ll ret = 0;
    each(c, s) ret = (ret << 8) | c;
    return ret;
}

void run() {
    int n; cin >> n;
    map<ll, Entry> elems;

    rep(i, 0, n) {
        string s; cin >> s;

        rep(a, 0, sz(s)) rep(b, a+1, sz(s)+1) {
            auto& elem = elems[encode(s.substr(a, b-a))];
            if (elem.str != s) {
                elem.str = s;
                elem.count++;
            }
        }
    }

    int q; cin >> q;

    while (q--) {
        string s; cin >> s;
        auto& elem = elems[encode(s)];
        cout << elem.count << ' ' << elem.str << '\n';
    }
}