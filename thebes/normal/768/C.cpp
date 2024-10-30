#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
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

const int MN = 1e5+5, MM = 1003;
int n, k, x, arr[2*MN], cnt[2*MM], huh[2*MM], ot[2*MM], i, j, mn=1<<30, mx, y, c, val[2*MM];
map<int,int> mp;

int main(){
    scanf("%d%d%d",&n,&k,&x);
    for(i=1;i<=n;i++){
        scanf("%d",&arr[i]);
        mp[arr[i]]=mp[arr[i]^x]=0;
    }
    i=0;
    for(auto it=mp.begin();it!=mp.end();it++)
        it->second = ++i, val[i]=it->first;
    for(auto v : mp){
        ot[v.second]=mp[v.first^x];
    }
    for(i=1;i<=n;i++){
        cnt[mp[arr[i]]]++;
    }
    // O(kx)
    for(i=1;i<=k;i++){
        int par = 1;
        for(j=1;j<=mp.size();j++)
            huh[j]=cnt[j];
        for(j=1;j<=mp.size();j++){
            y = cnt[j];
            if(!par){
                c = y/2;
                huh[ot[j]]+=c;
                huh[j]-=c;
            }
            else{
                c = ceil(y/2.0);
                huh[ot[j]]+=c;
                huh[j]-=c;
            }
            par ^= (cnt[j]&1);
        }
        swap(huh,cnt);
    }
    for(j=1;j<=mp.size();j++){
        if(cnt[j]){
            mx=max(mx,val[j]);
            mn=min(mn,val[j]);
        }
    }
    printf("%d %d\n",mx,mn);
    return 0;
}