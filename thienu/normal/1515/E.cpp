
#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll MOD;
const int MAXN = 420; // nice
vll factorial(MAXN);
vll factorial_inv(MAXN);

ll mul(ll a, ll b){
    return (a % MOD) * (b % MOD) % MOD;
}

ll add(ll a, ll b){
    ll res = ((a % MOD) + (b % MOD)) % MOD;
    if(res < 0){
        res = res + MOD;
    }
    return res;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1){
            ans = mul(ans, a);
        }
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inverse(ll x){
    return binexp(x, MOD-2);
}

ll ncr(ll n, ll r){
    return mul(factorial[n], mul(factorial_inv[r], factorial_inv[n-r]));
}

void precompute(){
    factorial[0] = 1;
    for(int i = 1; i < MAXN; i++){
        factorial[i] = mul(factorial[i-1], i);
    }
    for(int i = 0; i < MAXN; i++){
        factorial_inv[i] = inverse(factorial[i]);
    }
}

void solve(){
    int n;
    cin >> n >> MOD;

    precompute();

    // dp[size][length]
    vvll dp(n+1, vll(n+1));
    for(int i = 1; i <= n; i++){
        // debug(i);
        dp[i][i] = binexp(2, i-1);
    }

    for(int i = 3; i <= n; i++){
        for(int j = 1; j < i; j++){
            for(int k = 1; k <= i-2; k++){
                // debug(i, j, k);
                if(j-k < 0) continue;
                dp[i][j] = add(dp[i][j], mul(dp[i-k-1][j-k], mul(binexp(2, k-1), ncr(j, k))));
            }
            // debug(i, j, dp[i][j]);
        }
    }

    ll ans = 0;
    for(int i = 0; i <= n; i++){
        ans = add(ans, dp[n][i]);
    }
    cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}