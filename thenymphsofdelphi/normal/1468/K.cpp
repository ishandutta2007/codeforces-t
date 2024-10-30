#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

#define endl '\n'
#define fi first
#define se second
#define For(i, l, r) for (int i = l; i < r; i++)
#define ForE(i, l, r) for (int i = l; i <= r; i++)
#define FordE(i, l, r) for (int i = l; i >= r; i--)
#define Fora(v, a) for (auto v: a)
#define bend(a) a.begin(), a.end()
#define isz(a) ((signed)a.size())

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
typedef vector <vi> vvi;

const int N = 5e3 + 5;

int n;
string s;

void readTest(){
    cin >> s; n = s.length(); s = ' ' + s;
}

int dir[4] = {'U', 'R', 'D', 'L'};
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void resetTest(){
    
}

void solveTest(){
    pii coor = {0, 0};
    ForE(i, 1, n){
        For(j, 0, 4){
            if (dir[j] == s[i]){
                coor.fi += dx[j]; coor.se += dy[j];
                break;
            }
        }
        pii coor2 = {0, 0};
        ForE(j, 1, n){
            For(k, 0, 4){
                if (dir[k] == s[j]){
                    coor2.fi += dx[k]; coor2.se += dy[k];
                    if (coor2 == coor){
                        coor2.fi -= dx[k]; coor2.se -= dy[k];
                    }
                    break;
                }
            }
        }
        if (coor2 == make_pair(0, 0)){
            cout << coor.fi << ' ' << coor.se << endl;
            return;
        }
    }
    cout << 0 << ' ' << 0 << endl;
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
int q; cin >> q; while (q--){
    readTest();
    resetTest();
    solveTest();
}
}

/*
==================================================+
INPUT:                                            |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
OUTPUT:                                           |
--------------------------------------------------|

--------------------------------------------------|
==================================================+
*/