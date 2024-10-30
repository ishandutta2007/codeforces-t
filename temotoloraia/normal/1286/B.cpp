#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

#pragma GCC optimize ("O3")

#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
/*
#pragma comment(linker, "/STACK: 20000000005")
*/
//#define int long long

using namespace std;

const int N = 2005;

int n;
int a[N];
vector < int > g[N], v[N];

string ans = "YES";

int pas[N];

void dfs (int k, int p){
    for (int to : g[k]){
        dfs (to, k);
        for (int x : v[to]){
            if (a[k] == 0)
                v[k].pb (k);
            a[k]--;
            v[k].pb (x);
        }
    }
    if (a[k] == 0)
        v[k].pb (k);
    if (a[k] > 0)
        ans = "NO";
}

int S;


main() {
    ios_base::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int p;
        cin >> p >> a[i];
        if (p)
            g[p].pb (i);
        else
            S = i;
    }
    dfs (S, 0);
    cout << ans << endl;
    if (ans == "NO")
        return 0;
    for (int i = 0; i < n; i++)
        pas[v[S][i]] = i + 1;
    for (int i = 1; i <= n; i++)
        cout << pas[i] << " ";
    cout << endl;
}