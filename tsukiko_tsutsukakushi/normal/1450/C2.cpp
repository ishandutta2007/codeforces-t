/**
 *    author:  otera    
**/
#include<bits/stdc++.h>
using namespace std;

#define int long long
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll INF=1LL<<60;
#define rep(i, n) for(int i = 0; i < n; ++ i)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
#define fr first
#define sc second
#define all(c) c.begin(),c.end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

void solve() {
    int n; cin >> n;
    vector<vector<char>> f(n, vector<char>(n));
    int k = 0;
    rep(i, n) {
        rep(j, n) {
            cin >> f[i][j];
            if(f[i][j] != '.') {
                ++ k;
            }
        }
    }
    vector<vector<int>> num(n, vector<int>(n));
    rep(i, n) {
        rep(j, n) {
            num[i][j] = (i + j) % 3;
        }
    }
    vector<int> cnto(3, 0), cntx(3, 0);
    rep(i, n) {
        rep(j, n) {
            if(f[i][j] == 'O') cnto[num[i][j]] ++;
            if(f[i][j] == 'X') cntx[num[i][j]] ++;
        }
    }
    int ido = -1, idx = -1;
    int mi = inf;
    rep(i, 3) {
        rep(j, 3) {
            if(i == j) continue;
            if(chmin(mi, cnto[i] + cntx[j])) {
                ido = i, idx = j;
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            if(f[i][j] == 'O') if(num[i][j] == ido) f[i][j] = 'X';
            if(f[i][j] == 'X') if(num[i][j] == idx) f[i][j] = 'O';
        }
    }
    rep(i, n) {
        rep(j, n) {
            cout << f[i][j];
        }
        cout << "\n";
    }
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	//cout << fixed << setprecision(20);
	int t; cin >> t; rep(i, t)solve();
	// solve();
    return 0;
}