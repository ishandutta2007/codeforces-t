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

        vector<vector<ll>> a(N), s(N);
        vector<int> u(N);
        vector<ll> x(N);

        rep(i, N) cin >> u[i];
        rep(i, N) cin >> x[i];

        rep(i, N) a[--u[i]].eb(x[i]);

        rep(i, N){
            sort(rall(a[i]));
            int K = sz(a[i]);
            s[i].assign(K+1, 0);
            rep(j, K) s[i][j+1] = s[i][j]+a[i][j];
        }

        vector<int> v(N);
        iota(all(v), 0);
        sort(all(v), [&](int i, int j){
            return sz(a[i]) > sz(a[j]);
        });

        rep2(i, 1, N){
            ll ans = 0;

            rep(j, N){
                int k = v[j];

                if(sz(a[k]) < i) break;
                int K = sz(a[k]);
                //cout << k << ' ' << sz(s[k]) << ' ' << K-(K%i) << '\n';
                ans += s[k][K-(K%i)];
            }

            cout << ans << (i == N? '\n' : ' ');
        }
    }
}