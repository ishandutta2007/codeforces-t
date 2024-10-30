#include <bits/stdc++.h>

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;

using namespace std;

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
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

ll sum_to(int s, int pos, int restrict){
    vector<int> res;
    if(pos > 0){
        for(int i = 0; i < pos; i++){
            res.push_back(9);
            s -= 9;
        }
        if(s >= 8){
            res.push_back(8);
            s -= 8;
        }
    }
    else{
        res.push_back(min(s, restrict));
        s -= min(s, restrict);
    }
    while(s >= 9){
        res.push_back(9);
        s -= 9;
    }
    res.push_back(s);
    reverse(res.begin(), res.end());
    ll ans = 0;
    for(int i : res){
        ans *= 10;
        ans += i;
    }
    return ans;
}

void solve(){
    int n, k;
    cin >> n >> k;
    k++;
    ll ans = LLONG_MAX;
    for(int change = 0; change < k; change++){
        // change after position (k-1 means no change)
        for(int pos = 0; pos < 17; pos++){
            int offs = (k*(-2*change+k-1)/2) - 9 * pos * (k - change - 1);
            // if(offs < 0) continue;
            if(n - offs < 0) continue;
            if((n - offs) % k != 0) continue;
            debug(change, pos, offs);
            int s = (n - offs) / k;
            debug(s);
            if(9 * pos > s) continue;
            ll x = sum_to(s, pos, 10-k+change);
            debug(x);
            if(x-change >= 0) ans = min(ans, x-change);
        }
    }
    if(ans == LLONG_MAX) cout << -1 << endl;
    else cout << ans << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}