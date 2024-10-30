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

template<typename Monoid>
struct Segment_Tree{
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;
    
    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1){
        int m = sz(v);
        n = 1;
        while(n < m) n <<= 1;
        seg.assign(2*n, e1);
        copy(all(v), seg.begin()+n);
        for(int i = n-1; i > 0; i--) seg[i] = f(seg[2*i], seg[2*i+1]);
    }
    
    void change(int i, const Monoid &x){
        seg[i += n] = x;
        while(i >>= 1){
            seg[i] = f(seg[2*i], seg[2*i+1]);
        }
    }
 
    Monoid query(int l, int r) const{
        Monoid L = e1, R = e1;
        l += n, r += n;
        while(l < r){
            if(l&1) L = f(L, seg[l++]);
            if(r&1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }
 
    Monoid operator [] (int i) const {return seg[n+i];}
 
    template<typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, bool type) const{
        while(i < n){
            Monoid nxt = type? f(seg[2*i+type], M) : f(M, seg[2*i+type]);
            if(check(nxt, x)) i = 2*i+type;
            else M = nxt, i = 2*i+(type^1);
        }
        return i-n;
    }
 
    template<typename C>
    int find_first(int l, const C &check, const Monoid &x) const{
        Monoid L = e1;
        int a = l+n, b = n+n;
        while(a < b){
            if(a&1){
                Monoid nxt = f(L, seg[a]);
                if(check(nxt, x)) return find_subtree(a, check, x, L, false);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }
 
    template<typename C>
    int find_last(int r, const C &check, const Monoid &x) const{
        Monoid R = e1;
        int a = n, b = r+n;
        while(a < b){
            if(b&1 || a == 1){
                Monoid nxt = f(seg[--b], R);
                if(check(nxt, x)) return find_subtree(b, check, x, R, true);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

int main(){
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    vector<vector<int>> ids(N);
    rep(i, N){
        cin >> a[i] >> b[i]; a[i]--, b[i]--;
        ids[a[i]].eb(i);
    }

    vector<int> ans(N), p(N);
    priority_queue<pii, vector<pii>, greater<pii>> que;
    rep(i, N){
        each(e, ids[i]){
            que.emplace(b[e], e);
        }
        ans[que.top().second] = i;
        que.pop();
    }
    rep(i, N) p[ans[i]] = i;

    auto f = [](int a, int b) {return min(a, b);};
    vector<int> v(N);
    rep(i, N) v[i] = a[p[i]];
    Segment_Tree<int> seg(v, f, inf);

    rep(i, N){
        int L = i+1, R = b[p[i]]+1;
        if(seg.query(L, R) <= i){
            rep2(j, L, R-1){
                if(a[p[j]] <= i){
                    cout << "NO\n";
                    each(e, ans) cout << e+1 << ' '; cout << '\n';
                    swap(ans[p[i]], ans[p[j]]);
                    each(e, ans) cout << e+1 << ' '; cout << '\n';
                    return 0;
                }
            }
        }
    }

    cout << "YES\n";
    each(e, ans) cout << e+1 << ' '; cout << '\n';
}