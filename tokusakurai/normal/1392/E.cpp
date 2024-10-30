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
    int N; cin >> N;

    vector<vector<ll>> a(N, vector<ll>(N, 0));
    rep(i, 2*N-1){
        int sx, sy;
        if(i < N) sx = 0, sy = i;
        else sx = i-(N-1), sy = N-1;

        rep(j, min(i+1, 2*N-1-i)){
            if(j%2 == 0) a[sx+j][sy-j] = (1LL<<i); 
        }
    }

    rep(i, N){
        rep(j, N){
            cout << a[i][j];
            if(j == N-1) cout << endl;
            else cout << ' ';
        }
    }

    int Q; cin >> Q;

    while(Q--){
        ll K; cin >> K;
        int px = 0, py = 0, k = 0;

        while(true){
            cout << px+1 << ' ' << py+1 << endl;
            k++;

            if(px == N-1 && py == N-1) break;

            if(px == N-1) {py++; continue;}
            if(py == N-1) {px++; continue;}

            if(a[px+1][py] != 0){
                if((K>>k)&1) px++;
                else py++;
            }
            else{
                if((K>>k)&1) py++;
                else px++;
            }
        }
    }
}