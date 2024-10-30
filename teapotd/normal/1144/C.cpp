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

void run() {
    int n; cin >> n;
    Vi elems(n);
    each(e, elems) cin >> e;
    sort(all(elems));

    Vi inc, dec;

    each(e, elems) {
        if (inc.empty() || inc.back() != e) {
            inc.pb(e);
        } else if (dec.empty() || dec.back() != e) {
            dec.pb(e);
        } else {
            cout << "NO\n";
            return;
        }
    }

    swap(inc, dec);
    reverse(all(dec));

    cout << "YES\n" << sz(inc) << '\n';
    each(e, inc) cout << e << ' ';
    cout << '\n' << sz(dec) << '\n';
    each(e, dec) cout << e << ' ';
    cout << '\n';
}