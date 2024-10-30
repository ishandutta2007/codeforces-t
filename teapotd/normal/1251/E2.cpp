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
    int t; cin >> t;

    while (t--) {
        int n; cin >> n;
        vector<Pii> elems(n);

        each(e, elems) {
            cin >> e.x >> e.y;
        }

        sort(all(elems));

        priority_queue<int, Vi, greater<int>> avail;
        int taken = 0;
        ll ans = 0;

        for (int i = n-1; i >= 0; i--) {
            auto e = elems[i];
            avail.push(e.y);

            int req = e.x-i-taken;

            while (req > 0) {
                ans += avail.top();
                avail.pop();
                taken++;
                req--;
            }
        }

        cout << ans << '\n';
    }
}