#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using ld=long double;
using ull=unsigned long long;
using uint=unsigned int;
using pcc=pair<char,char>;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using pdd=pair<double,double>;
using tuplis=pair<ll,pll>;
using tuplis2=pair<pll,ll>;
template<class T> using pq=priority_queue<T,vector<T>,greater<T>>;
const ll LINF=0x1fffffffffffffff;
const int INF=0x3fffffff;
const ll MOD=1000000007;
const ll MODD=998244353;
const ld DINF=numeric_limits<ld>::infinity();
const ld EPS=1e-9;
const vector<ll>four{0,1,0,-1,0};
#define _overload4(_1,_2,_3,_4,name,...) name
#define _overload3(_1,_2,_3,name,...) name
#define _rep1(n) for(ll i=0;i<n;++i)
#define _rep2(i,n) for(ll i=0;i<n;++i)
#define _rep3(i,a,b) for(ll i=a;i<b;++i)
#define _rep4(i,a,b,c) for(ll i=a;i<b;i+=c)
#define rep(...) _overload4(__VA_ARGS__,_rep4,_rep3,_rep2,_rep1)(__VA_ARGS__)
#define _rrep1(n) for(ll i=n-1;i>=0;i--)
#define _rrep2(i,n) for(ll i=n-1;i>=0;i--)
#define _rrep3(i,a,b) for(ll i=b-1;i>=a;i--)
#define _rrep4(i,a,b,c) for(ll i=a+(b-a-1)/c*c;i>=a;i-=c)
#define rrep(...) _overload4(__VA_ARGS__,_rrep4,_rrep3,_rrep2,_rrep1)(__VA_ARGS__)
#define each(i,a) for(auto &i:a)
#define sum(...) accumulate(range(__VA_ARGS__),0LL)
#define dsum(...) accumulate(range(__VA_ARGS__),double(0))
#define _range(i) (i).begin(),(i).end()
#define _range2(i,k) (i).begin(),(i).begin()+k
#define _range3(i,a,b) (i).begin()+a,(i).begin()+b
#define range(...) _overload3(__VA_ARGS__,_range3,_range2,_range)(__VA_ARGS__)
#define _rrange(i) (i).rbegin(),(i).rend()
#define _rrange2(i,k) (i).rbegin(),(i).rbegin()+k
#define _rrange3(i,a,b) (i).rbegin()+a,(i).rbegin()+b
#define rrange(...) _overload3(__VA_ARGS__,_rrange3,_rrange2,_rrange)(__VA_ARGS__)
#define elif else if
#define unless(a) if(!(a))
#define mp make_pair
#define mt make_tuple
#define INT(...) int __VA_ARGS__;in(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;in(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;in(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;in(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;in(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;in(__VA_ARGS__)
#define vec(type,name,...) vector<type> name(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);in(name)
#define vv(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__))
#define VV(type,name,h,...) vector<vector<type>>name(h,vector<type>(__VA_ARGS__));in(name)
#define vvv(type,name,h,w,...) vector<vector<vector<type>>>name(h,vector<vector<type>>(w,vector<type>(__VA_ARGS__)))
inline constexpr ll gcd(ll a,ll b){if(!a||!b)return 0;while(b){ll c=b;b=a%b;a=c;}return a;}
inline constexpr ll lcm(ll a,ll b){if(!a||!b)return 0;return a*b/gcd(a,b);}
template<class T> inline constexpr T min(vector<T> &v){return *min_element(range(v));}
inline char min(string &v){return *min_element(range(v));}
template<class T> inline constexpr T max(vector<T> &v){return *max_element(range(v));}
inline char max(string &v){return *max_element(range(v));}
inline constexpr ll intpow(ll a,ll b){ll ans=1;for(ll i=1;b;i*=2){if(b&i){b^=i;ans*=a;}a*=a;}return ans;}
inline constexpr ll modpow(ll a,ll b,ll mod = MOD){ll ans=1;for(ll i=1;b;i*=2){if(b&i){b^=i;ans*=a;ans%=mod;}a*=a;a%=mod;}return ans;}
template<typename T>
inline constexpr bool chmin(T &mn,const T &cnt){if(mn>cnt){mn=cnt;return 1;}else return 0;}
template<typename T>
inline constexpr bool chmax(T &mx,const T &cnt){if(mx<cnt){mx=cnt;return 1;}else return 0;}
inline int scan(){ return getchar(); }
inline void scan(int &a){ scanf("%d", &a); }
inline void scan(unsigned &a){ scanf("%u", &a); }
inline void scan(long &a){ scanf("%ld", &a); }
inline void scan(long long &a){ scanf("%lld", &a); }
inline void scan(unsigned long long &a){ scanf("%llu", &a); }
inline void scan(char &a){ cin >> a; }
inline void scan(float &a){ scanf("%f", &a); }
inline void scan(double &a){ scanf("%lf", &a); }
inline void scan(long double &a){ scanf("%Lf", &a); }
inline void scan(vector<bool> &vec){ for(unsigned i = 0; i < vec.size(); i++) { int a; scan(a); vec[i] = a; } }
inline void scan(string &a){ cin >> a; }
template<class T> inline void scan(vector<T> &vec);
template<class T, size_t size> inline void scan(array<T, size> &vec);
template<class T, class L> inline void scan(pair<T, L> &p);
template<class T, size_t size> inline void scan(T (&vec)[size]);
template<class T> inline void scan(vector<T> &vec){ for(auto &i : vec) scan(i); }
template<class T, size_t size> inline void scan(array<T, size> &vec){ for(auto &i : vec) scan(i); }
template<class T, class L> inline void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template<class T, size_t size> inline void scan(T (&vec)[size]){ for(auto &i : vec) scan(i); }
template<class T> inline void scan(T &a){ cin>>a; }
inline void in(){}
template <class Head, class... Tail> inline void in(Head &head, Tail&... tail){ scan(head); in(tail...); }
inline void print(){ putchar('\n'); }
inline void print(const bool &a){ printf("%d", a); }
inline void print(const int &a){ printf("%d", a); }
inline void print(const unsigned &a){ printf("%u", a); }
inline void print(const long &a){ printf("%ld", a); }
inline void print(const long long &a){ printf("%lld", a); }
inline void print(const unsigned long long &a){ printf("%llu", a); }
inline void print(const char &a){ printf("%c", a); }
inline void print(const char a[]){ printf("%s", a); }
inline void print(const float &a){ printf("%.10f", a); }
inline void print(const double &a){ printf("%.10f", a); }
inline void print(const long double &a){ printf("%.10Lf", a); }
template<class T> void print(const vector<T> &vec);
template<class T, size_t size> void print(const array<T, size> &vec);
template<class T, class L> void print(const pair<T, L> &p);
template<class T, size_t size> inline void print(const T (&vec)[size]);
template<class T> void print(const vector<T> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, size_t size> void print(const array<T, size> &vec){ print(vec[0]); for(auto i = vec.begin(); ++i != vec.end(); ){ putchar(' '); print(*i); } }
template<class T, class L> void print(const pair<T, L> &p){ print(p.first); putchar(' '); print(p.second); }
template<class T, size_t size> inline void print(const T (&vec)[size]){ print(vec[0]); for(auto i = vec; ++i != end(vec); ){ putchar(' '); print(*i); } }
template<class T> inline void print(const T &a){ cout << a; }
inline int out(){ putchar('\n'); return 0; }
template<class T> inline int out(const T &t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> inline int out(const Head &head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
template <class T> inline void err(T t){cerr<<t<<'\n';}
inline void err(){cerr<<'\n';}
inline int yes(const bool &i){return out(i?"yes":"no");}
inline int Yes(const bool &i){return out(i?"Yes":"No");}
inline int YES(const bool &i){return out(i?"YES":"NO");}
inline int Yay(const bool &i){return out(i?"Yay!":":(");}
inline int Possible(const bool &i){return out(i?"Possible":"Impossible");}
inline int POSSIBLE(const bool &i){return out(i?"POSSIBLE":"IMPOSSIBLE");}
inline void Case(ll i){printf("Case #%lld: ",i);}



constexpr ll mod = MODD;
inline constexpr ll extgcd(ll a, ll b, ll &x, ll &y){ ll g = a; x = 1; y = 0; if(b){ g = extgcd(b, a % b, y, x); y -= a / b * x; } return g; }
inline constexpr ll invmod(ll a, ll m = mod){ ll x = 0, y = 0; extgcd(a, m, x, y); return (x + m) % m; }
struct Modint{
    ll _num;
    constexpr Modint() : _num() { _num = 0; }
    constexpr Modint(ll x) : _num() { _num = x % mod; if(_num < 0) _num += mod; }
    inline constexpr Modint operator= (int x){ _num = x % mod; if(_num<0) _num += mod; return *this; }
    inline constexpr Modint operator= (ll x){ _num = x % mod; if(_num<0) _num += mod; return *this; }
    inline constexpr Modint operator= (Modint x){ _num = x._num; return *this; }
    inline constexpr Modint operator+ (int x){ return Modint(_num + x); }
    inline constexpr Modint operator+ (ll x){ return Modint(_num + x); }
    inline constexpr Modint operator+ (Modint x){ ll a = _num + x._num; if(a >= mod) a -= mod; return Modint{a}; }
    inline constexpr Modint operator+=(int x){ _num += x; _num %= mod; if(_num < 0) _num += mod; return *this; }
    inline constexpr Modint operator+=(ll x){ _num += x; _num %= mod; if(_num < 0) _num += mod; return *this; }
    inline constexpr Modint operator+=(Modint x){ _num += x._num; if(_num >= mod) _num -= mod; return *this; }
    inline constexpr Modint operator++(){ if(_num == mod - 1) _num = 0; else _num++; return *this; }
    inline constexpr Modint operator- (int x){ return Modint(_num - x); }
    inline constexpr Modint operator- (ll x){ return Modint(_num - x); }
    inline constexpr Modint operator- (Modint x){ ll a = _num - x._num; if(a < 0) a += mod; return Modint{a}; }
    inline constexpr Modint operator-=(int x){ _num -= x; _num %= mod; if(_num < 0) _num += mod; return *this; }
    inline constexpr Modint operator-=(ll x){ _num -= x; _num %= mod; if(_num < 0) _num += mod; return *this; }
    inline constexpr Modint operator-=(Modint x){ _num -= x._num; if(_num < 0) _num += mod; return *this; }
    inline constexpr Modint operator--(){ if(_num == 0) _num = mod - 1; else _num--; return *this; }
    inline constexpr Modint operator* (int x){ return Modint(_num * (x % mod)); }
    inline constexpr Modint operator* (ll x){ return Modint(_num * (x % mod)); }
    inline constexpr Modint operator* (Modint x){ return Modint{_num * x._num % mod}; }
    inline constexpr Modint operator*=(int x){ _num *= Modint(x); _num %= mod; return *this; }
    inline constexpr Modint operator*=(ll x){ _num *= Modint(x); _num %= mod; return *this; }
    inline constexpr Modint operator*=(Modint x){ _num *= x._num; _num %= mod; return *this; }
    inline constexpr Modint operator/ (int x){ return Modint(_num * invmod(Modint(x), mod)); }
    inline constexpr Modint operator/ (ll x){ return Modint(_num * invmod(Modint(x), mod)); }
    inline constexpr Modint operator/ (Modint x){ return Modint{_num * invmod(x._num, mod) % mod}; }
    inline constexpr Modint operator/=(int x){ _num *= invmod(Modint(x), mod); _num %= mod; return *this; }
    inline constexpr Modint operator/=(ll x){ _num *= invmod(Modint(x), mod); _num %= mod; return *this; }
    inline constexpr Modint operator/=(Modint x){ _num *= invmod(x._num, mod); _num %= mod; return *this; }
    inline constexpr Modint pow(ll x){ ll i = 1; Modint ans = 1, cnt = *this; while(i <= x){ if(x & i){ ans *= cnt; x ^= i; } cnt *= cnt; i *= 2; } return ans; }
    inline constexpr operator ll() const { return _num; }
};
vector<Modint> fac(1, 1), inv(1, 1);
inline void reserve(ll a){
    if(fac.size() >= a) return;
    if(a < fac.size() * 2) a = fac.size() * 2;
    if(a >= mod) a = mod;
    while(fac.size() < a) fac.push_back(fac.back() * ll(fac.size()));
    inv.resize(fac.size());
    inv.back() = Modint(1) / fac.back();
    for(ll i = inv.size() - 1; !inv[i - 1]; i--) inv[i - 1] = inv[i] * i;
}
inline Modint fact(ll n){ if(n < 0) return 0; reserve(n + 1); return fac[n]; }
inline Modint perm(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(n + 1); return fac[n] * inv[n - r]; }
inline Modint comb(ll n, ll r){ if(r < 0 || n < r) return 0; reserve(n + 1); return fac[n] * inv[r] * inv[n - r]; }
inline Modint Mcomb(ll n, ll r){ return comb(n + r - 1, n - 1); } // rn



int main(){
    LL(n,m);
    VEC(ll,a,n);
    vec(Modint,w,n);
    each(i,w){
        LL(a);
        i=a;
    }
    Modint plus=0,minus=0;
    rep(n){
        if(a[i])plus+=w[i];
        else minus+=w[i];
    }
    vector<Modint>ans(n);
    vec(Modint,p,m+1);
    p[0]=1;
    rep(m){
        vec(Modint,p2,m+1);
        rep(j,m){
            p2[j]+=p[j]*(minus-i+j)/(plus+j+minus-i+j);
            p2[j+1]+=p[j]*(plus+j)/(plus+j+minus-i+j);
        }
        p.swap(p2);
    }
    rep(j,n){
        if(a[j])rep(m+1){
            ans[j]+=w[j]*p[i];
            w[j]+=w[j]/(plus+i);
        }
        else rrep(m+1){
            ans[j]+=w[j]*p[i];
            w[j]-=w[j]/(minus-(m-i));
        }
    }
    each(i,ans)out(i);
}