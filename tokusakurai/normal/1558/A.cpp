#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i <= n; i++)
#define rep3(i, x, n) for(int i = x; i >= n; i--)
#define each(e, v) for(auto &e: v)
#define pb push_back
#define eb emplace_back
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
using ll = long long;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;
const int MOD = 1000000007;
//const int MOD = 998244353;
const int inf = (1<<30)-1;
const ll INF = (1LL<<60)-1;
template<typename T> bool chmax(T &x, const T &y) {return (x < y)? (x = y, true) : false;};
template<typename T> bool chmin(T &x, const T &y) {return (x > y)? (x = y, true) : false;};

struct io_setup{
    io_setup(){
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

template<typename T>
void print(const vector<T> &v, T x = 0){
    int n = v.size();
    for(int i = 0; i < n; i++) cout << v[i]+x << (i == n-1? '\n' : ' ');
}

template<typename T>
void printn(const vector<T> &v, T x = 0){
    int n = v.size();
    for(int i = 0; i < n; i++) cout << v[i]+x << '\n';
}

template<typename T>
int lb(const vector<T> &v, T x){
    return lower_bound(begin(v), end(v), x)-begin(v);
}

template<typename T>
int ub(const vector<T> &v, T x){
    return upper_bound(begin(v), end(v), x)-begin(v);
}

template<typename T>
void unique(vector<T> &v){
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template<typename T>
vector<int> iota(const vector<T> &v, bool greater = false){
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j){
        return greater? v[i] > v[j] : v[i] < v[j];
    });
    return ret;
}

int main(){
    int T; cin >> T;

    while(T--){
        int A, B; cin >> A >> B;

        vector<bool> ok(A+B+1, false);

        int X = (A+B)/2, Y = A+B-X;
        rep2(i, 0, A){ //i
            if(X-i >= 0 && A-i <= Y) ok[(X-i)+(A-i)] = true;
        }
        swap(X, Y);
        rep2(i, 0, A){ //i
            if(X-i >= 0 && A-i <= Y) ok[(X-i)+(A-i)] = true;
        }

        vector<int> ans;
        rep2(i, 0, A+B){
            if(ok[i]) ans.eb(i);
        }

        cout << sz(ans) << '\n';
        print(ans);
    }
}