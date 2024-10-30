#include<bits/stdc++.h>
using namespace std;

// Optimization

//#pragma GCC optimize("O3")
#define endl '\n'

// Shortcut

#define int long long
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

const int N = 20 + 5, M = 1e3 + 5, mod = 1e9 + 7, mod1 = 998244353, mod2 = 1e9 + 9, inf = 1e18 + 7;
const ll infll = 1e18 + 7;

int n;
int a[M];
int b[N][N];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    ForE(i, 1, n * n){
        int x; cin >> x; a[x]++;
    }
    if (n % 2 == 0){
        vi cand;
        ForE(i, 1, 1000){
            if (a[i] && a[i] % 4 == 0){
                For(j, 0, a[i] / 4){
                    cand.pb(i);
                }
            }
        }
        if (cand.size() * 4 != n * n) Ptest("NO");
        cout << "YES" << endl;
        int idx = 0;
        ForE(i, 1, n){
            ForE(j, 1, n){
                if (!b[i][j]){
                    b[i][j] = cand[idx];
                    b[n + 1 - i][j] = cand[idx];
                    b[i][n + 1 - j] = cand[idx];
                    b[n + 1 - i][n + 1 - j] = cand[idx];
                    idx++;
                }
                cout << b[i][j] << ' ';
            }
            cout << endl;
        }
        return 0;
    }
    vi cand4, cand2;
    int cal4 = (n / 2) * (n / 2), cal2 = n - 1;
    ForE(i, 1, 1000){
        if (a[i] >= 4){
            int x = a[i] / 4;
            For(j, 0, x){
                cand4.pb(i);
                a[i] -= 4;
                cal4--;
                if (cal4 <= 0){
                    break;
                }
            }
        }
        if (cal4 <= 0){
            break;
        }
    }
    if (cal4 > 0) Ptest("NO");
    ForE(i, 1, 1000){
        if (a[i] >= 2){
            int x = a[i] / 2;
            For(j, 0, x){
                cand2.pb(i);
                a[i] -= 2;
                cal2--;
                if (cal2 <= 0){
                    break;
                }
            }
        }
        if (cal2 <= 0){
            break;
        }
    }
    if (cal2 > 0) Ptest("NO");
    cout << "YES" << endl;
    ForE(i, 1, 1000){
        if (a[i]){
            b[n / 2 + 1][n / 2 + 1] = i;
            break;
        }
    }
    int idx4 = 0, idx2 = 0;
    ForE(i, 1, n){
        ForE(j, 1, n){
            if (i != n + 1 - i && j != n + 1 - j && !b[i][j]){
                b[i][j] = cand4[idx4];
                b[n + 1 - i][j] = cand4[idx4];
                b[i][n + 1 - j] = cand4[idx4];
                b[n + 1 - i][n + 1 - j] = cand4[idx4];
                idx4++;
            }
            else if ((!(i == n + 1 - i && j == n + 1 - j)) && !b[i][j]){
                b[i][j] = cand2[idx2];
                b[n + 1 - i][j] = cand2[idx2];
                b[i][n + 1 - j] = cand2[idx2];
                idx2++;
            }
            cout << b[i][j] << ' ';
        }
        cout << endl;
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