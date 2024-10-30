#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC optimize("no-stack-protector")
#pragma GCC target("sse,sse2,ssse3,sse3,sse4,popcnt,avx,mmx,abm,tune=native")
#include <bits/stdc++.h>
#define DEBUG 1
using namespace std;

namespace output{
    void __(short x){cout<<x;}
    void __(unsigned x){cout<<x;}
    void __(int x){cout<<x;}
    void __(long long x){cout<<x;}
    void __(unsigned long long x){cout<<x;}
    void __(double x){cout<<x;}
    void __(long double x){cout<<x;}
    void __(char x){cout<<x;}
    void __(const char*x){cout<<x;}
    void __(const string&x){cout<<x;}
    void __(bool x){cout<<(x?"true":"false");}
    template<class S,class T>
    void __(const pair<S,T>&x){__(DEBUG?"(":""),__(x.first),__(DEBUG?", ":" "),__(x.second),__(DEBUG?")":"");}
    template<class T>
    void __(const vector<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const set<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class T>
    void __(const multiset<T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    template<class S,class T>
    void __(const map<S,T>&x){__(DEBUG?"{":"");bool _=0;for(const auto&v:x)__(_?DEBUG?", ":" ":""),__(v),_=1;__(DEBUG?"}":"");}
    void pr(){cout<<"\n";}
    template<class S,class... T>
    void pr(const S&a,const T&...b){__(a);if(sizeof...(b))__(' ');pr(b...);}
}

using namespace output;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<int,char> pic;
typedef pair<double,double> pdd;
typedef pair<ld,ld> pld;
typedef vector<int> vi;
typedef vector<ll> vl;

#define pb push_back
#define fox(i,x,y) for(int i=(x);i<=(y);i++)
#define foxr(i,x,y) for(int i=(y);i>=(x);i--)
#define F first
#define S second

const int MN = 3e5+15;
ll n, i, j, x, y, cur, ans, lim[MN], cnt[MN], rev[MN], lo, hi, mid, t, m;
pll arr[MN], A; map<ll,ll> mp, mp2; __int128 bit[MN];

void upd(int p,ll cost){
    for(int i=p;i<=m;i+=i&-i) bit[i]+=cost;
    for(int i=p;i<=m;i+=i&-i) cnt[i]++;
}

int cqu(int p){int ret=0;for(;p;p-=p&-p)ret+=cnt[p]; return ret;}
__int128 qu(ll p){__int128 r=0;for(;p;p-=p&-p)r+=bit[p]; return r;}

int main(){
    scanf("%lld",&n);
    scanf("%lld%lld",&A.F,&A.S);
    mp[A.F]=0;
    for(n--,i=1;i<=n;i++){
        scanf("%lld%lld",&arr[i].F,&arr[i].S);
        mp[arr[i].F]=0; mp2[arr[i].S-arr[i].F+1]=0;
    }
    i=0; ans = n;
    for(auto it=mp.begin();it!=mp.end();it++)
        it->second = ++i, lim[i] = it->first;
    i=0; t = mp.size();
    for(auto it=mp2.begin();it!=mp2.end();it++)
        it->second = ++i, rev[i] = it->first;
    sort(arr+1,arr+n+1,[](pll i,pll j){return i.F>j.F;});
    m = mp2.size();
    for(i=t,j=1;i>=0;i--){
        if(lim[i]>A.F) continue;
        while(j<=n&&arr[j].F>lim[i]){
            upd(mp2[arr[j].S-arr[j].F+1],arr[j].S-arr[j].F+1);
            j++;
        }
        ll tot = cqu(m);
        lo = 1, hi = m+1;
        while(lo<hi){
            mid=(lo+hi)>>1;
            if(qu(mid)>A.F-lim[i]) hi=mid;
            else lo=mid+1;
        }
        if(lo==m+1){ans=0; continue;}
        __int128 pog = qu(lo-1), cc = cqu(lo-1);
        ans=min(ans,(ll)(tot-cc-(A.F-lim[i]-pog)/rev[lo]));
    }
    printf("%lld\n",ans+1);
    return 0;
}