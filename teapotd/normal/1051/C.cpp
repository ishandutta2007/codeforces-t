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
    int n; cin >> n;
    Vi seq(n);
    Vi counts(100);

    each(x, seq) {
        cin >> x;
        x--;
        counts[x]++;
    }

    int nice = 0;
    rep(i, 0, 100) if (counts[i] == 1) nice++;

    int dif = 0;
    bool one = (nice % 2);

    if (one) {
        bool ok = 0;
        each(x, seq) if (counts[x] > 2) {
            ok = 1;
            break;
        }
        if (!ok) {
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";

    each(x, seq) {
        bool st = 0;

        if (counts[x] == 1) {
            if (dif <= 0) {
                dif++;
                st = 0;
            } else {
                dif--;
                st = 1;
            }
        } else if (counts[x] > 2 && one) {
            one = false;
            dif--;
            st = 1;
        }

        cout << (st ? 'A' : 'B');
    }

    cout << endl;
}