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

void dfs(int u, vi &vis, vvi &adj, vi &best, vi &ans, vi &dist){
    if(vis[u]) return;
    vis[u] = 1;
    ans[u] = best[u];
    for(int v : adj[u]){
        if(dist[v] <= dist[u]) continue;
        dfs(v, vis, adj, best, ans, dist);
        ans[u] = min(ans[u], ans[v]);
    }
}

void solve(){
    int n, m;
    cin >> n >> m;

    vvi adj(n);
    for(int i = 0; i < m; i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        adj[x].push_back(y);
    }

    debug(adj);
    
    vi dist(n, 1e9 + 7);
    vi dist_vis(n);
    queue<pii> q;
    q.push({0, 0});
    dist_vis[0] = 1;

    while(!q.empty()){
        int d, v;
        tie(v, d) = q.front();
        debug(v);
        q.pop();
        dist[v] = min(dist[v], d);
        for(int u : adj[v]){
            if(!dist_vis[u]){
                dist_vis[u] = 1;
                q.push({u, d+1});
            }
        }
    }

    vi best(n);
    for(int i = 0; i < n; i++){
        best[i] = dist[i];
        for(int u : adj[i]){
            best[i] = min(best[i], dist[u]);
        }
    }

    vi ans(n, 1e9 + 7);
    vi vis(n);

    dfs(0, vis, adj, best, ans, dist);

    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
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