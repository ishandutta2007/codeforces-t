#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

int main(){
    int T; cin >> T;

    while(T--){
        int N; cin >> N;

        vector<int> a(N);
        rep(i, N) cin >> a[i];

        if(N == 1 && a[0] == 1) {cout << "1 1\n"; continue;}

        vector<int> check, nxt(N);
        rep(i, N){
            int j = (i+1)%N;
            nxt[i] = j;
            if(i != j && gcd(a[i], a[j]) == 1) check.eb(i);
        }

        vector<int> ans;
        int ng = -1;

        while(true){
            if(check.empty()) break;

            vector<int> tmp;

            each(e, check){
                if(ng == e) continue;
                
                ans.eb(nxt[e]);
                ng = nxt[e];
                nxt[e] = nxt[nxt[e]];

                if(nxt[e] != e && gcd(a[e], a[nxt[e]]) == 1) tmp.eb(e);
                if(nxt[e] == e && a[e] == 1) {ans.eb(e); break;}
            }

            swap(check, tmp);
        }

        cout << sz(ans);
        each(e, ans) cout << ' ' << e+1;
        cout << '\n';
    }
}