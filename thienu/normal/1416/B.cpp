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
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

void solve(){
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];
    int sum = accumulate(v.begin(), v.end(), 0);
    if(sum % n != 0){
        cout << -1 << endl;
        return;
    }
    int target = sum / n;
    vector<tuple<int, int, int>> ans;
    set<int> remaining;
    for(int i = 1; i < n; i++) remaining.insert(i);
    while(!remaining.empty()){
        for(int j : remaining){
            if(v[j] % (j+1) == 0){
                ans.push_back({j+1, 1, v[j] / (j+1)});
                v[0] += v[j];
                v[j] = 0;
                remaining.erase(j);
                goto end;
            }
            // check if j can be pushed
            if(v[j] % (j + 1) + v[0] >= j + 1){
                ans.push_back({1, j+1, j + 1 - v[j] % (j + 1)});
                v[0] -= j + 1 - v[j] % (j + 1);
                v[j] += j + 1 - v[j] % (j + 1);
                ans.push_back({j+1, 1, v[j] / (j+1)});
                v[0] += v[j];
                v[j] = 0;
                remaining.erase(j);
                goto end;
            }
        }
        cout << -1 << endl;
        return;
        end:
        continue;
    }
    for(int i = 1; i < n; i++){
        ans.push_back({1, i+1, target});
    }
    cout << ans.size() << endl;
    for(tuple<int, int, int> x : ans){
        cout << get<0>(x) << " " << get<1>(x) << " " << get<2>(x) << endl;
    }
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