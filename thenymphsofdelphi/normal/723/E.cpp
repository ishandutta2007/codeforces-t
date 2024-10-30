#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

//#define int long long
#define eb emplace_back
#define pb push_back
#define pob pop_back
#define mp make_pair
#define upb upper_bound
#define lwb lower_bound
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define Ford(i, r, l) for (int i = r; i > l; i--)
#define FordE(i, r, l) for (int i = r; i >= l; i--)
#define Fora(i, a) for (auto i : a)

// I/O & Debug

#define PrintV(a) Fora(iiii, a) cout << iiii << ' '; cout << endl;
#define PrintVl(a) Fora(iiii, a) cout << iiii << endl;
#define PrintA(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << ' '; cout << endl;
#define PrintAl(a, l, r) for (int iiii = l; iiii <= r; iiii++) cout << a[iiii] << endl;
#define Ptest(x) return cout << x, 0;
#define gl(s) getline(cin, s);
#define setpre(x) fixed << setprecision(x)
/*
#define debug(args...){ string _sDEB = #args; replace(_sDEB.begin(), _sDEB.end(), ',', ' '); stringstream _ssDEB(_sDEB); istream_iterator<string> _itDEB(_ssDEB); DEB(_itDEB, args); }
void DEB(istream_iterator<string> it) {}
template<typename T, typename... Args>
void DEB(istream_iterator<string> it, T a, Args... args){
    cout << *it << " = " << a << endl;
    DEB(++it, args...);
}
*/

// Functions

//#define isvowel(a) (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
#define bend(a) a.begin(), a.end()
#define rbend(a) a.rbegin(), a.rend()
#define mset(a) memset(a, 0, sizeof(a))
#define mset1(a) memset(a, 1, sizeof(a))
#define msetn1(a) memset(a, -1, sizeof(a))
#define msetinf(a) memset(a, 0x3f, sizeof(a))
#define gcd __gcd
#define __builtin_popcount __builtin_popcountll
//mt19937 rando(chrono::steady_clock::now().time_since_epoch().count());

// Data Structure

#define pque priority_queue
#define mts multiset
#define y0 _y0_
#define y1 _y1_
#define div divi
typedef long long ll;
typedef long double ld;
typedef vector <int> vi;
typedef vector <ll> vll;
typedef vector <ld> vld;
typedef vector <string> vs;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef vector <vi > vvi;
typedef vector <vll > vvll;
typedef vector <pii > vpii;
typedef vector <pll > vpll;

const int N = 2e2 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e9 + 7;
const ll infll = 1e18 + 7;

int n, m, ans;
bool adj[N][N];
int sz[N];
vi euler_cycle;

void euler(int u){
    ForE(i, 1, n + 1){
        if (adj[u][i]){
            adj[u][i] = 0;
            adj[i][u] = 0;
            euler(i);
        }
    }
    euler_cycle.pb(u);
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
int q; cin >> q;
while (q--){
    cin >> n >> m;
    ans = n;
    euler_cycle.clear();
    ForE(i, 1, n + 1){
        sz[i] = 0;
        ForE(j, 1, n + 1){
            adj[i][j] = 0;
        }
    }
    ForE(i, 1, m){
        int u, v; cin >> u >> v;
        adj[u][v] = 1; adj[v][u] = 1;
        sz[u]++; sz[v]++;
    }
    ForE(i, 1, n){
        if (sz[i] & 1){
            adj[n + 1][i] = 1;
            adj[i][n + 1] = 1;
            ans--;
        }
    }
    cout << ans << endl;
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (adj[i][j]){
                euler(i);
                //cout << "A ";
                //PrintV(euler_cycle);
                For(i, 1, euler_cycle.size()){
                    if (euler_cycle[i] != n + 1 && euler_cycle[i - 1] != n + 1){
                        cout << euler_cycle[i - 1] << ' ' << euler_cycle[i] << endl;
                    }
                }
                euler_cycle.clear();
            }
        }
    }
}
}

/*
==================================+
INPUT:                            |
------------------------------    |

------------------------------    |
==================================+
OUTPUT:                           |
------------------------------    |

------------------------------    |
==================================+
*/