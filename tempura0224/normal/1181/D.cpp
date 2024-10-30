#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<iomanip>
#include<math.h>
#include<complex>
#include<queue>
#include<deque>
#include<stack>
#include<map>
#include<set>
#include<bitset>
#include<functional>
#include<assert.h>
#include<numeric>
using namespace std;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
using ll = long long;
const int inf=1e9+7;
const ll longinf=1LL<<60 ;
const ll mod=1e9+7 ;

template<typename T>
struct SegmentTree{
private:
    int n;
    T E;
    vector<T> node;
    inline void updatef(T& x,T& y){
        x = y;
        //x += y;
        //x = max(x,y);
        //x = min(x,y);
    }
    inline T queryf(T& x,T& y){
        return x+y;
        //return x+y;
        //return max(x,y);
        //return min(x,y);
    }

public:
    SegmentTree(int sz,T E_):E(E_){
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
    }

    SegmentTree(vector<T>& A,T E_):E(E_){
        int sz=A.size();
        n=1;
        while(n<sz)n<<=1;
        node.resize(2*n-1,E);
        rep(i,sz)node[i+n-1]=A[i];
        for(int i=n-2;i>=0;--i){
            node[i]=queryf(node[2*i+1], node[2*i+2]);
        }
    }
    void update(int k,T x){
        k+=n-1;
        updatef(node[k],x);
        while(k>0){
            k=(k-1)/2;
            node[k]=queryf(node[2*k+1], node[2*k+2]);
        }
    }
       //[a,b)
    T get(int a,int b,int k=0,int l=0,int r=-1){
        if(r<0)r=n;
        if(r<=a||b<=l)return E;
        if(a<=l&&r<=b)return node[k];
        T xl=get(a,b,2*k+1,l,(l+r)/2);
        T xr=get(a,b,2*k+2,(l+r)/2,r);
        return queryf(xl, xr);
    }
    T find(int x,int k = 0, int l= 0, int r = -1){
        if(r<0)r=n;
        if(r-l==1)return l;
        if(node[2*k+1]>=x){
            return find(x,2*k+1,l,(l+r)/2);
        }
        else {
            x -= node[2*k+1];
            return find(x,2*k+2,(l+r)/2,r);
        }
    }
};

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    vector<int> cnt(m);
    rep(i,n){
        int x;
        scanf("%d",&x);
        --x;
        cnt[x]++;
    }
    priority_queue<pair<ll,int>,vector<pair<ll,int>>, greater<pair<ll,int>>> pq;
    rep(i,m)pq.emplace(cnt[i],i);
    vector<ll> c(q);
    rep(i,q){
        scanf("%lld",&c[i]);
    }
    vector<int> ans(q);
    vector<int> ord(q);
    iota(ord.begin(),ord.end(),0);
    sort(ord.begin(),ord.end(),[&](int x,int y){
        return c[x]<c[y];
    });
    ll cur = n;
    ll sz = 0;
    ll h = 0;
    ll maxi = 0;
    SegmentTree<int> sg(m,0);
    for(auto i : ord){
        while(cur + maxi < c[i]){
            cur += maxi;
            h = pq.top().first;
            while(pq.size()&&pq.top().first==h){
                int v = pq.top().second;
                sg.update(v,1);
                ++sz;
                pq.pop();
            }
            maxi = longinf;
            if(pq.size()) maxi = (pq.top().first - h) * sz;
        }
        c[i]-=cur;
        assert(c[i]>0);
        ll res = (c[i]-1)%sz + 1;
        ans[i] = sg.find(res);
    }
    rep(i,q)printf("%d\n",ans[i]+1);
    return 0;
}