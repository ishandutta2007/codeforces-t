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

// upsolved
void solve(){
    vector<ll> nums(3);
    cin >> nums[0] >> nums[1] >> nums[2];

    cout << "First" << endl;

    while(true){
        debug(nums);
        ll x;
        if(abs(nums[0] - nums[1]) == abs(nums[1] - nums[2])
              || abs(nums[0] - nums[1]) == abs(nums[2] - nums[0])
              || abs(nums[2] - nums[0]) == abs(nums[1] - nums[2])){
            x = accumulate(nums.begin(), nums.end(), 0LL) - 2 * (*min_element(nums.begin(), nums.end())) - *max_element(nums.begin(), nums.end());
        }
        else{
            x = 3 * (*max_element(nums.begin(), nums.end())) - accumulate(nums.begin(), nums.end(), 0LL);
        }
        cout << x << endl;
        cout.flush();
        int res;
        cin >> res;
        if(res == 0 || res == -1) break;
        res--;
        nums[res] += x;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}