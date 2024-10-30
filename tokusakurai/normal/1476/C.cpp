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

        vector<ll> c(N), a(N), b(N), d(N);
        int gomi;
        rep(i, N) cin >> c[i];
        cin >> gomi;
        rep(i, N-1) {cin >> a[i]; a[i]--;}
        cin >> gomi;
        rep(i, N-1) {cin >> b[i]; b[i]--;}
        a[N-1] = 0, b[N-1] = c[N-1]-1;
        rep(i, N){
            d[i] = abs(a[i]-b[i]);
            if(a[i] > b[i]) swap(a[i], b[i]);
        }

        int ptr = 0;
        ll ans = 0;
        while(ptr < N){
            ll tmp = -INF;
            int j = 0;
            while(ptr+j < N){
                int i = ptr+j;
                tmp += 2+a[i]+(c[i]-1-b[i]);
                chmax(ans, tmp+d[i]);
                chmax(tmp, d[i]);
                if(j > 0 && d[i] == 0) break;
                j++;
            }
            ptr += j;
        }

        cout << ans << '\n';
    }
}