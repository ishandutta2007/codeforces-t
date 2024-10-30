//template start//
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
using namespace std;
#define katai_gaand_faad_speed ios::sync_with_stdio(0);cin.tie(0);
#define F first
#define S second
#define pb push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vi>
#define vvl vector<vl>
#define vpi vector<pi>
#define vpl vector<pl>
#define pi pair<int,int>
#define pl pair<ll,ll>
#define all(x) x.begin(),x.end()
typedef long double ld; 
typedef double dd;
typedef long long ll;
const int MOD = 998244353; // = (119<<23)+1
const ll INF = 1e18; 
const ld PI = 4*atan((ld)1); 
//intitialization->ordered_set<int>  s;.....can do all set functions.......s.order_of_key(2)(// the number of elements in the set s strictly less than 2)
//use this ->   using namespace __gnu_pbds;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//*s.find_by_order(0)(print the 0-th smallest number in s(0-based)).....
template<typename T>
void printvector(vector<T>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<' ';
    }
    cout<<"\n";
}
template<typename T>
void printarray(T a[])
{
    for(int i=0;i<a.size();i++)
    {
        cout<<a[i]<<" "; 
    }
    cout<<"\n";
}
 
void printpairs(vector<pair<int,int>>& v){
    for(int i=0;i<v.size();i++){
        cout<<v[i].F<<','<<v[i].S<<'|';
    }
    cout<<endl;
}
 
void print2d(vector<vector<int>>&v){
    for(int i=0;i<v.size();i++){
        printvector(v[i]);
    }
}
//exponent in log(m) time
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
//nCr with modulo
ll R=MOD; 
// modinv((x-1)!)=modinv(x)*x
ll modInverse(ll n) { 
    return exp(n, R-2,R);
} 
ll ncr(ll n, ll r) 
{ 
    if (r==0) return 1; 
        vector<ll>fac(n+1,1); 
        for (ll i=1 ; i<=n; i++) 
        fac[i] = fac[i-1]*i%R; 
        return ((fac[n]*modInverse(fac[r]) % R)*modInverse(fac[n-r])%R)%R;
}
//prime factorization can be done in log(n) after a precomputaion of O(nlog(log(n)))
//(In sieve storing the smallest prime factor of each number upto n)
//sieve for spf
void sieve(int n,vi&spf)
{
    for(int i=0;i<n;i++) spf[i]=i;
    for(int i=2;i<n;i++)
    {
        if(spf[i]==i)
        {
            for(ll j=((ll)i)*((ll)i);j<n;j+=i)
            {
                if(spf[j]==j) spf[j]=i;
            }
        }
    }
}
//prime factorization in root(n)//
void factorize(long long n,vpi&v) 
{ 
    int count = 0; 
    while (!(n % 2)) { 
        n >>= 1;  
        count++; 
    } 
  
    if (count) 
        v.push_back(make_pair(2,count)); 
  
    for (long long i = 3; i <= sqrt(n); i += 2) { 
        count = 0; 
        while (n % i == 0) { 
            count++; 
            n = n / i; 
        } 
        if (count) 
            v.push_back(make_pair(i,count));
    } 
  
    if (n > 2) 
        v.push_back(make_pair(n,1));
} 
//2d grids
int mv_x[]={1,-1,0,0};
int mv_y[]={0,0,1,-1};
char dir[]={'D','U','R','L'};
map <char,pi> mv={{'D',{1,0}},{'U',{-1,0}},{'R',{0,1}},{'L',{0,-1}}};
//
#define TT int T;cin>>T;for(int tt=1;tt<=T;tt++)
//template ends//
//ImpPoints
//1) string insert function is way faster than loop insertion
//2)Use binary exp instead of log,pow(they work well with doubles)
//3)if accesing any index then keep check that the index exists
//4) use(int) with v.size() calculations always.
//nxt,k,u,n
bool solve(int a , int b , int c, int d)
{
    if(a>=0 and a <= d and a >= b-c and a <= 2*d-c-b)
    {
        return true;
    }
    return false;
}
int main()
{
    katai_gaand_faad_speed;  
    int n, k;
    cin>>n>>k;
    vi dp(n + 1, -1),nxt(n + 1);
    queue<int> q;
    q.push(n);
    dp[n] = 0;
    while (q.size()) {
        int u = q.front();
        int total;
        q.pop();
        for (int i = k; i >= 0; i -= 2) {
            int ahead = u + i;
            int backward = u - i;
            if (solve(ahead,k,u,n)) {
                if (dp[ahead] == -1) {
                    nxt[ahead] = u;
                    q.push(ahead);
                    dp[ahead] = dp[u] + 1;
                }
            }
            if (solve(backward,k,u,n)) {
                if (dp[backward] == -1) {
                    nxt[backward] = u;
                    q.push(backward);
                    dp[backward] = dp[u] + 1;
                }
            }
        }
    } 
    if(dp[0]==-1)
    {
        cout<<-1<<endl;
        return 0;
    }
    //cout<<dp[0]<<endl;
    ll ans=0;
    vi cur;
    int sz = cur.size();
    vi query;
    int sz1,temp=k;
    while ((int)cur.size()!=n) 
    {
        temp=k;
        map<int,int> temp_M;
        sz = cur.size();
        sz1 = nxt[sz];
        query.clear();
        while (sz + temp > sz1) {
            query.pb(cur.back());
            cur.pop_back();
            temp--;
            sz--;
        }
        for (auto node: query) 
        {
            temp_M[node]=1;
        }
        for (auto node: cur) 
        {
            temp_M[node]=1;
        }
        for (int i = 1; i <= n; i++) {
            if (temp_M[i]) continue;
            query.pb(i);
            cur.pb(i);
            temp--;
            if (temp == 0) break;
        }
        ll temp;
        cout<<"? ";
        for (auto node: query) {
            cout<<node<<" ";
        }
        cout<<endl;
        cin >> temp;
        ans^=temp;
    }
    cout<<"! ";
    cout<<ans<<endl;
}