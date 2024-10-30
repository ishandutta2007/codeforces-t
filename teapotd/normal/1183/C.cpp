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

void run() {
    int q; cin >> q;

    while (q--) {
        ll k, n, a, b; cin >> k >> n >> a >> b;

        ll begin = 0, end = n+1;

        while (begin+1 < end) {
            ll mid = (begin+end) / 2;

            if (a*mid + b*(n-mid) >= k) {
                end = mid;
            } else {
                begin = mid;
            }
        }

        if (a*begin + b*(n-begin) >= k) {
            cout << -1 << '\n';
        } else {
            cout << begin << '\n';
        }
    }
}