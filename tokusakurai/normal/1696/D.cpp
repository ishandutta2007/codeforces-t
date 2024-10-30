#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep2(i, x, n) for (int i = x; i <= n; i++)
#define rep3(i, x, n) for (int i = x; i >= n; i--)
#define each(e, v) for (auto &e : v)
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

template <typename T>
bool chmax(T &x, const T &y) {
    return (x < y) ? (x = y, true) : false;
}

template <typename T>
bool chmin(T &x, const T &y) {
    return (x > y) ? (x = y, true) : false;
}

template <typename T>
int flg(T x, int i) {
    return (x >> i) & 1;
}

template <typename T>
void print(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << (i == n - 1 ? '\n' : ' ');
    if (v.empty()) cout << '\n';
}

template <typename T>
void printn(const vector<T> &v, T x = 0) {
    int n = v.size();
    for (int i = 0; i < n; i++) cout << v[i] + x << '\n';
}

template <typename T>
int lb(const vector<T> &v, T x) {
    return lower_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
int ub(const vector<T> &v, T x) {
    return upper_bound(begin(v), end(v), x) - begin(v);
}

template <typename T>
void rearrange(vector<T> &v) {
    sort(begin(v), end(v));
    v.erase(unique(begin(v), end(v)), end(v));
}

template <typename T>
vector<int> id_sort(const vector<T> &v, bool greater = false) {
    int n = v.size();
    vector<int> ret(n);
    iota(begin(ret), end(ret), 0);
    sort(begin(ret), end(ret), [&](int i, int j) { return greater ? v[i] > v[j] : v[i] < v[j]; });
    return ret;
}

template <typename S, typename T>
pair<S, T> operator+(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first + q.first, p.second + q.second);
}

template <typename S, typename T>
pair<S, T> operator-(const pair<S, T> &p, const pair<S, T> &q) {
    return make_pair(p.first - q.first, p.second - q.second);
}

template <typename S, typename T>
istream &operator>>(istream &is, pair<S, T> &p) {
    S a;
    T b;
    is >> a >> b;
    p = make_pair(a, b);
    return is;
}

template <typename S, typename T>
ostream &operator<<(ostream &os, const pair<S, T> &p) {
    return os << p.first << ' ' << p.second;
}

struct io_setup {
    io_setup() {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout << fixed << setprecision(15);
    }
} io_setup;

const int inf = (1 << 30) - 1;
const ll INF = (1LL << 60) - 1;
const int MOD = 1000000007;
// const int MOD = 998244353;

template <typename Monoid>
struct Segment_Tree {
    using F = function<Monoid(Monoid, Monoid)>;
    int n;
    vector<Monoid> seg;
    const F f;
    const Monoid e1;

    // f(f(a,b),c) = f(a,f(b,c)), f(e1,a) = f(a,e1) = a

    Segment_Tree(const vector<Monoid> &v, const F &f, const Monoid &e1) : f(f), e1(e1) {
        int m = v.size();
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2 * n, e1);
        copy(begin(v), end(v), seg.begin() + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    Segment_Tree(int m, const Monoid &x, const F &f, const Monoid &e1) : f(f), e1(e1) {
        n = 1;
        while (n < m) n <<= 1;
        seg.assign(2 * n, e1);
        vector<Monoid> v(m, x);
        copy(begin(v), end(v), begin(seg) + n);
        for (int i = n - 1; i > 0; i--) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    void change(int i, const Monoid &x, bool update = true) {
        if (update) {
            seg[i + n] = x;
        } else {
            seg[i + n] = f(seg[i + n], x);
        }
        i += n;
        while (i >>= 1) seg[i] = f(seg[2 * i], seg[2 * i + 1]);
    }

    Monoid query(int l, int r) const {
        Monoid L = e1, R = e1;
        l += n, r += n;
        while (l < r) {
            if (l & 1) L = f(L, seg[l++]);
            if (r & 1) R = f(seg[--r], R);
            l >>= 1, r >>= 1;
        }
        return f(L, R);
    }

    Monoid operator[](int i) const { return seg[n + i]; }

    template <typename C>
    int find_subtree(int i, const C &check, const Monoid &x, Monoid &M, int type) const {
        while (i < n) {
            Monoid nxt = type ? f(seg[2 * i + type], M) : f(M, seg[2 * i + type]);
            if (check(nxt, x)) {
                i = 2 * i + type;
            } else {
                M = nxt;
                i = 2 * i + (type ^ 1);
            }
        }
        return i - n;
    }

    template <typename C>
    int find_first(int l, const C &check, const Monoid &x) const { // check(( [l,r] ), x)  r
        Monoid L = e1;
        int a = l + n, b = n + n;
        while (a < b) {
            if (a & 1) {
                Monoid nxt = f(L, seg[a]);
                if (check(nxt, x)) return find_subtree(a, check, x, L, 0);
                L = nxt, a++;
            }
            a >>= 1, b >>= 1;
        }
        return n;
    }

    template <typename C>
    int find_last(int r, const C &check, const Monoid &x) const { // check(( [l,r) ), x)  l
        Monoid R = e1;
        int a = n, b = r + n;
        while (a < b) {
            if ((b & 1) || a == 1) {
                Monoid nxt = f(seg[--b], R);
                if (check(nxt, x)) return find_subtree(b, check, x, R, 1);
                R = nxt;
            }
            a >>= 1, b >>= 1;
        }
        return -1;
    }
};

int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        vector<int> p(N), q(N);
        rep(i, N) {
            cin >> p[i];
            p[i]--;
            q[p[i]] = i;
        }

        auto f1 = [](int a, int b) { return min(a, b); };
        auto f2 = [](int a, int b) { return max(a, b); };
        auto c1 = [](int a, int b) { return a <= b; };
        auto c2 = [](int a, int b) { return a >= b; };

        vector<int> a1(N), b1(N); // p[i] 
        vector<int> a2(N), b2(N); // p[i] 

        set<int> s1, s2;
        s1.emplace(-1), s1.emplace(N);
        rep3(i, N - 1, 0) {
            auto it = s1.upper_bound(q[i]);
            b1[q[i]] = *it - 1;
            it--;
            a1[q[i]] = *it + 1;
            s1.emplace(q[i]);
        }
        s2.emplace(-1), s2.emplace(N);
        rep(i, N) {
            auto it = s2.upper_bound(q[i]);
            b2[q[i]] = *it - 1;
            it--;
            a2[q[i]] = *it + 1;
            s2.emplace(q[i]);
        }
        // print(a1), print(b1);

        Segment_Tree<int> seg1(a1, f1, inf), seg2(b1, f2, -inf);
        Segment_Tree<int> seg3(a2, f1, inf), seg4(b2, f2, -inf);
        queue<int> que;
        vector<int> d(N, inf);
        d[0] = 0;
        que.emplace(0);

        {
            int t = 0;
            seg1.change(t, inf);
            seg2.change(t, -inf);
            seg3.change(t, inf);
            seg4.change(t, -inf);
        }

        while (!empty(que)) {
            int i = que.front();
            que.pop();
            {
                int l = a1[i];
                while (true) {
                    if (l >= i || seg4.query(l, i) < i) break;
                    int t = seg4.find_first(l, c2, i);
                    if (chmin(d[t], d[i] + 1)) {
                        que.emplace(t);
                        seg1.change(t, inf);
                        seg2.change(t, -inf);
                        seg3.change(t, inf);
                        seg4.change(t, -inf);
                    }
                    l = t + 1;
                }

                int r = b1[i];
                while (true) {
                    if (r <= i || seg3.query(i + 1, r + 1) > i) break;
                    int t = seg3.find_last(r + 1, c1, i);
                    if (chmin(d[t], d[i] + 1)) {
                        que.emplace(t);
                        seg1.change(t, inf);
                        seg2.change(t, -inf);
                        seg3.change(t, inf);
                        seg4.change(t, -inf);
                    }
                    r = t - 1;
                }
            }
            {
                int l = a2[i];
                while (true) {
                    if (l >= i || seg2.query(l, i) < i) break;
                    int t = seg2.find_first(l, c2, i);
                    if (chmin(d[t], d[i] + 1)) {
                        que.emplace(t);
                        seg1.change(t, inf);
                        seg2.change(t, -inf);
                        seg3.change(t, inf);
                        seg4.change(t, -inf);
                    }
                    l = t + 1;
                }

                int r = b2[i];
                while (true) {
                    if (r <= i || seg1.query(i + 1, r + 1) > i) break;
                    int t = seg1.find_last(r + 1, c1, i);
                    if (chmin(d[t], d[i] + 1)) {
                        que.emplace(t);
                        seg1.change(t, inf);
                        seg2.change(t, -inf);
                        seg3.change(t, inf);
                        seg4.change(t, -inf);
                    }
                    r = t - 1;
                }
            }
        }

        cout << d[N - 1] << '\n';
    }
}