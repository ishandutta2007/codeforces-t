#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Vi = vector<int>;
using Pii = pair<int,int>;
#define pb push_back
#define x first
#define y second
#define rep(i,b,e) for(int i = (b); i < (e); i++)
#define each(a,x) for (auto& a : (x))
#define all(x) (x).begin(),(x).end()
#define sz(x) int((x).size())
#define tem template<class t,class u,class...w>
#define pri(x,y)tem auto operator<<(t&o,u a)->decltype(x,o) { o << y; return o; }
pri(a.print(), "{"; a.print(); o << "}")
pri(a.y, "("<<a.x<<", "<<a.y<<")")
pri(all(a), "["; auto d="";for(auto i : a)(o<<d<<i,d=", ");o<<"]")
void DD(...) {}
tem void DD(t s, u a, w... k) {
    int b = 44;
    while (*s && *s != b) {
        b += (*s == 40 ? 50 : *s == 41 ? -50 : 0);
        cerr << *s++;
    }
    cerr << ": " << a << *s++; DD(s, k...);
}
tem vector<t> span(const t* a, u n) { return {a,a+n}; }
#ifdef LOC
#define deb(...) (DD("#, "#__VA_ARGS__,__LINE__,__VA_ARGS__),cerr<<endl)
#else
#define deb(...)
#endif
#define DBP(...) void print() { DD(#__VA_ARGS__,__VA_ARGS__); }

ll n, a, b, T;
string str;

ll solve() {
    ll suf = 0;
    ll sufTime = 0;

    each(c, str) {
        sufTime += a+1;
        if (c == 'w') sufTime += b;
    }

    ll prefTime = 0;
    ll ans = 0;

    rep(i, 0, n) {
        prefTime++;
        if (str[i] == 'w') prefTime += b;
        if (prefTime > T) break;

        while (suf < n) {
            ll spent = prefTime + i*a + sufTime;
            if (spent <= T) break;
            sufTime -= a+1;
            if (str[suf] == 'w') sufTime -= b;
            suf++;
        }

        ans = max(ans, n-suf+i+1);
        prefTime += a;
    }

    return ans;
}

int main() {
    cin.sync_with_stdio(0); cin.tie(0);
    cout << fixed << setprecision(18);

    cin >> n >> a >> b >> T >> str;
    ll ans = solve();
    reverse(str.begin()+1, str.end());
    ans = max(ans, solve());
    cout << min(ans, n) << endl;
    return 0;
}