#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using uint = unsigned;
using pcc = pair<char, char>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tuplis = array<ll, 3>;
template<class T> using pq = priority_queue<T, vector<T>, greater<T>>;
const ll LINF=0x1fffffffffffffff;
const ll MINF=0x7fffffffffff;
const int INF=0x3fffffff;
const int MOD=1000000007;
const int MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const ld PI=3.1415926535897932;
const ll dx[] = {0, 1, 0, -1, 1, -1, 1, -1};
const ll dy[] = {1, 0, -1, 0, 1, 1, -1, -1};
#define overload4(_1,_2,_3,_4,name,...) name
#define overload3(_1,_2,_3,name,...) name
#define rep1(n) for(ll i=0;i<n;++i)
#define rep2(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i<b;++i)
#define rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) overload4(__VA_ARGS__,rep4,rep3,rep2,rep1)(__VA_ARGS__)
#define rrep1(n) for(ll i=n;i--;)
#define rrep2(i,n) for(ll i=n;i--;)
#define rrep3(i,a,b) for(ll i=b;i-->(a);)
#define rrep4(i,a,b,c) for(ll i=(a)+((b)-(a)-1)/(c)*(c);i>=(a);i-=c)
#define rrep(...) overload4(__VA_ARGS__,rrep4,rrep3,rrep2,rrep1)(__VA_ARGS__)
#define each1(i,a) for(auto&&i:a)
#define each2(x,y,a) for(auto&&[x,y]:a)
#define each3(x,y,z,a) for(auto&&[x,y,z]:a)
#define each(...) overload4(__VA_ARGS__,each3,each2,each1)(__VA_ARGS__)
#define all1(i) begin(i),end(i)
#define all2(i,a) begin(i),begin(i)+a
#define all3(i,a,b) begin(i)+a,begin(i)+b
#define all(...) overload3(__VA_ARGS__,all3,all2,all1)(__VA_ARGS__)
#define rall1(i) (i).rbegin(),(i).rend()
#define rall2(i,k) (i).rbegin(),(i).rbegin()+k
#define rall3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rall(...) overload3(__VA_ARGS__,rall3,rall2,rall1)(__VA_ARGS__)
#define sum(...) accumulate(all(__VA_ARGS__),0LL)
#define dsum(...) accumulate(all(__VA_ARGS__),0.0L)
#define Msum(...) accumulate(all(__VA_ARGS__),0_M)
#define elif else if
#define unless(a) if(!(a))
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;in(__VA_ARGS__)
#define Sort(a) sort(all(a))
#define Rev(a) reverse(all(a))
#define Uniq(a) sort(all(a));a.erase(unique(all(a)),end(a))
#define vec(type,name,...) vector<type>name(__VA_ARGS__)
#define VEC(type,name,size) vector<type>name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
template<class T> auto min(const T& a){ return *min_element(all(a)); }
template<class T> auto max(const T& a){ return *max_element(all(a)); }
inline ll popcnt(ull a){ return __builtin_popcountll(a); }
ll intpow(ll a, ll b){ ll ans = 1; while(b){ if(b & 1) ans *= a; a *= a; b /= 2; } return ans; }
ll modpow(ll a, ll b, ll p){ ll ans = 1; while(b){ if(b & 1) (ans *= a) %= p; (a *= a) %= p; b /= 2; } return ans; }
template<class T> bool chmin(T& a, const T& b){ if(a > b){ a = b; return 1; } return 0; }
template<class T> bool chmax(T& a, const T& b){ if(a < b){ a = b; return 1; } return 0; }
template<class T, class U> bool chmin(T& a, const U& b){ if(a > T(b)){ a = b; return 1; } return 0; }
template<class T, class U> bool chmax(T& a, const U& b){ if(a < T(b)){ a = b; return 1; } return 0; }
vector<ll> iota(ll n, ll begin = 0){ vector<ll> a(n); iota(a.begin(), a.end(), begin); return a; }
vector<pll> factor(ull x){ vector<pll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
map<ll,ll> factor_map(ull x){ map<ll,ll> ans; for(ull i = 2; i * i <= x; i++) if(x % i == 0){ ans[i] = 1; while((x /= i) % i == 0) ans[i]++; } if(x != 1) ans[x] = 1; return ans; }
vector<ll> divisor(ull x){ vector<ll> ans; for(ull i = 1; i * i <= x; i++) if(x % i == 0) ans.push_back(i); rrep(ans.size() - (ans.back() * ans.back() == x)) ans.push_back(x / ans[i]); return ans; }
template<class T> unordered_map<T, ll> press(vector<T> a){ Uniq(a); unordered_map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
template<class T> map<T, ll> press_map(vector<T> a){ Uniq(a); map<T, ll> ans; rep(a.size()) ans[a[i]] = i; return ans; }
int scan(){ return getchar(); }
void scan(int& a){ scanf("%d", &a); }
void scan(unsigned& a){ scanf("%u", &a); }
void scan(long& a){ scanf("%ld", &a); }
void scan(long long& a){ scanf("%lld", &a); }
void scan(unsigned long long& a){ scanf("%llu", &a); }
void scan(char& a){ do{ a = getchar(); }while(a == ' ' || a == '\n'); }
void scan(float& a){ scanf("%f", &a); }
void scan(double& a){ scanf("%lf", &a); }
void scan(long double& a){ scanf("%Lf", &a); }
void scan(vector<bool>& a){ for(unsigned i = 0; i < a.size(); i++){ int b; scan(b); a[i] = b; } }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto&& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto&& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto&& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto&& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void in(){}
template <class... T> void in(T&... a){ (void)initializer_list<int>{ (scan(a), 0)... }; }
void print(){ putchar(' '); }
void print(bool a){ printf("%d", a); }
void print(int a){ printf("%d", a); }
void print(unsigned a){ printf("%u", a); }
void print(long a){ printf("%ld", a); }
void print(long long a){ printf("%lld", a); }
void print(unsigned long long a){ printf("%llu", a); }
void print(char a){ printf("%c", a); }
void print(char a[]){ printf("%s", a); }
void print(const char a[]){ printf("%s", a); }
void print(float a){ printf("%.15f", a); }
void print(double a){ printf("%.15f", a); }
void print(long double a){ printf("%.15Lf", a); }
void print(const string& a){ for(auto&& i : a) print(i); }
template<class T> void print(const complex<T>& a){ if(a.real() >= 0) print('+'); print(a.real()); if(a.imag() >= 0) print('+'); print(a.imag()); print('i'); }
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ putchar(' '); print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
#ifdef DEBUG
inline ll __lg(ull x){ return 63 - __builtin_clzll(x); }
#define debug(...) { print(#__VA_ARGS__); print(":"); out(__VA_ARGS__); }
#else
#define debug(...) void(0)
#endif
int first(bool i = true){ return out(i?"first":"second"); }
int First(bool i = true){ return out(i?"First":"Second"); }
int yes(bool i = true){ return out(i?"yes":"no"); }
int Yes(bool i = true){ return out(i?"Yes":"No"); }
int No(){ return out("No"); }
int YES(bool i = true){ return out(i?"YES":"NO"); }
int NO(){ return out("NO"); }
int Yay(bool i = true){ return out(i?"Yay!":":("); }
int possible(bool i = true){ return out(i?"possible":"impossible"); }
int Possible(bool i = true){ return out(i?"Possible":"Impossible"); }
int POSSIBLE(bool i = true){ return out(i?"POSSIBLE":"IMPOSSIBLE"); }
void Case(ll i){ printf("Case #%lld: ", i); }



constexpr uint mod = MODD;
struct Modint{
    uint num = 0;
    constexpr Modint() noexcept {}
    constexpr Modint(const Modint &x) noexcept : num(x.num){}
    inline constexpr operator ll() const noexcept { return num; }
    inline constexpr Modint& operator+=(Modint x) noexcept { num += x.num; if(num >= mod) num -= mod; return *this; }
    inline constexpr Modint& operator++() noexcept { if(num == mod - 1) num = 0; else num++; return *this; }
    inline constexpr Modint operator++(int) noexcept { Modint ans(*this); operator++(); return ans; }
    inline constexpr Modint operator-() const noexcept { return Modint(0) -= *this; }
    inline constexpr Modint& operator-=(Modint x) noexcept { if(num < x.num) num += mod; num -= x.num; return *this; }
    inline constexpr Modint& operator--() noexcept { if(num == 0) num = mod - 1; else num--; return *this; }
    inline constexpr Modint operator--(int) noexcept { Modint ans(*this); operator--(); return ans; }
    inline constexpr Modint& operator*=(Modint x) noexcept { num = ull(num) * x.num % mod; return *this; }
    inline constexpr Modint& operator/=(Modint x) noexcept { return operator*=(x.inv()); }
    template<class T> constexpr Modint(T x) noexcept {
        using U = typename conditional<sizeof(T) >= 4, T, int>::type;
        U y = x; y %= U(mod); if(y < 0) y += mod; num = uint(y);
    }
    template<class T> inline constexpr Modint operator+(T x) const noexcept { return Modint(*this) += x; }
    template<class T> inline constexpr Modint& operator+=(T x) noexcept { return operator+=(Modint(x)); }
    template<class T> inline constexpr Modint operator-(T x) const noexcept { return Modint(*this) -= x; }
    template<class T> inline constexpr Modint& operator-=(T x) noexcept { return operator-=(Modint(x)); }
    template<class T> inline constexpr Modint operator*(T x) const noexcept { return Modint(*this) *= x; }
    template<class T> inline constexpr Modint& operator*=(T x) noexcept { return operator*=(Modint(x)); }
    template<class T> inline constexpr Modint operator/(T x) const noexcept { return Modint(*this) /= x; }
    template<class T> inline constexpr Modint& operator/=(T x) noexcept { return operator/=(Modint(x)); }
    inline constexpr Modint inv() const noexcept { ll x = 0, y = 0; extgcd(num, mod, x, y); return x; }
    static inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y) noexcept { ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
    inline constexpr Modint pow(ull x) const noexcept { Modint ans = 1, cnt = *this; while(x){ if(x & 1) ans *= cnt; cnt *= cnt; x /= 2; } return ans; }
};
std::istream& operator>>(std::istream& is, Modint& x){ ll a; in(a); x = a; return is; }
inline constexpr Modint operator""_M(ull x) noexcept { return Modint(x); }
std::vector<Modint> fac(1, 1), inv(1, 1);
inline void reserve(ll a){
    if(fac.size() >= a) return;
    if(a < fac.size() * 2) a = fac.size() * 2;
    if(a >= mod) a = mod;
    while(fac.size() < a) fac.push_back(fac.back() * Modint(fac.size()));
    inv.resize(fac.size());
    inv.back() = fac.back().inv();
    for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline Modint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline Modint perm(ll n, ll r){
    if(r < 0 || n < r) return 0;
    if(n >> 24){ Modint ans = 1; for(ll i = 0; i < r; i++) ans *= n--; return ans; }
    reserve(n + 1); return fac[n] * inv[n - r];
}
inline Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(r + 1); return perm(n, r) * inv[r]; }
inline Modint Mcomb(ll n, ll r){ return comb(n + r - 1, n - 1); } // r balls into n boxes
inline Modint catalan(ll n){ reserve(n * 2 + 1); return fac[n * 2] * inv[n] * inv[n + 1]; }
struct UnWeightedEdge{
    ll to;
    static constexpr ll cost = 1;
    UnWeightedEdge(){}
    UnWeightedEdge(ll to): to(to){}
    operator ll() const { return to; }
};
struct UnWeightedGraph{
    using E = UnWeightedEdge;
    vector<vector<E>> g;
    UnWeightedGraph(){}
    UnWeightedGraph(ll n): g(n){}
    vector<E>& operator[](ll at){ return g[at]; }
    operator vector<vector<E>>&(){ return g; }
    auto begin(){ return g.begin(); }
    auto end(){ return g.end(); }
    auto begin() const { return g.cbegin(); }
    auto end() const { return g.cend(); }
    ll size() const { return g.size(); }
    void resize(ll n){ g.resize(n); }
    const vector<E>& operator[](ll at) const { return g[at]; }
    operator const vector<vector<E>>&() const { return g; }
    void add_edge(ll a, ll b){
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }
    void add_directed_edge(ll from, ll to){
        g[from].emplace_back(to);
    }
    template<ll start_index = 1> void input_graph(ll m){
        while(m--){
            ll a, b;
            scanf("%lld%lld", &a, &b);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b);
            g[b].emplace_back(a);
        }
    }
    template<ll start_index = 1> void input_directed_graph(ll m){
        while(m--){
            ll a, b;
            scanf("%lld%lld", &a, &b);
            a -= start_index;
            b -= start_index;
            g[a].emplace_back(b);
        }
    }
    template<ll start_index = 1> void input_tree(ll n = -1){ if(n == -1) n = g.size(); input_graph<start_index>(n - 1); }
};
ll r;
struct T{
    vector<Modint>white={1},black={1};
    Modint ok=0;
    T rankup() const {
        T ans=*this;
        auto&b=ans.black,&w=ans.white;
        b.insert(b.begin(),0);
        Modint x=0;
        if(b.size()-1>r){
            x=b.back();
            b.pop_back();
        }
        w.insert(w.begin(),x);
        if(w.size()-1>r){
            ans.ok+=w.back();
            w.pop_back();
        }
        return ans;
    }
    T operator+(const T& t) const {
        T ans;
        auto&b=ans.black,&w=ans.white;
        const ll n=max(white.size(),t.white.size());
        b.assign(n,0);
        w.assign(n,0);
        rep(white.size())rep(j,t.white.size())w[max(i,j)]+=white[i]*t.white[j];
        rep(black.size())rep(j,t.black.size())b[min(i,j)]+=black[i]*t.black[j];
        rep(white.size())rep(j,t.black.size())(i+j>r?w[i]:b[j])+=white[i]*t.black[j];
        rep(black.size())rep(j,t.white.size())(i+j>r?w[j]:b[i])+=black[i]*t.white[j];
        ans.ok=(Msum(white)+Msum(black)+ok)*t.ok+(Msum(t.white)+Msum(t.black))*ok;
        return ans;
    }
};
int main(){
    LL(n);
    UnWeightedGraph g(n);
    g.input_tree();
    Modint ans=0;
    for(r=1;r<=n;r++){
        vec(T,dp,n);
        auto dfs = [&](ll from, ll at, auto dfs) -> void {
            each(i, g[at]) if(i != from){
                dfs(at, i, dfs);
                dp[at]=dp[at]+dp[i].rankup();
            }
        };
        dfs(-1, 0, dfs);
        ans+=dp[0].ok+Msum(dp[0].white);
    }
    ans--;
    ans/=2_M .pow(n);
    out(ans);
}