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
    ll N, K;
    cin >> N >> K;
    vector<ll> a(N), b(N);
    rep(i, N) cin >> a[i] >> b[i];

    vector<vector<bool>> dp(N+1, vector<bool>(K, false));
    dp[0][0] = true;
    ll S = 0;

    rep(i, N){
        S += a[i]+b[i];
        rep(j, K){
            if(j > a[i]) continue;
            ll x = a[i]-j, y = b[i];
            if((x+y)%K > y) continue;
            rep(k, K){
                if(dp[i][k]) dp[i+1][(k+j)%K] = true;
            }
        }
    }

    ll ans = 0;
    rep(i, K){
        if(dp[N][i]) chmax(ans, S/K);
        S--;
    }

    cout << ans << '\n';
}