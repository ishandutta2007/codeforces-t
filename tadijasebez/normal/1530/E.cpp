#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ldb double
template<typename T>void ckmn(T&a,T b){a=min(a,b);}
template<typename T>void ckmx(T&a,T b){a=max(a,b);}
void rd(int&x){scanf("%i",&x);}
void rd(ll&x){scanf("%lld",&x);}
void rd(char*x){scanf("%s",x);}
void rd(ldb&x){scanf("%lf",&x);}
void rd(string&x){scanf("%s",&x);}
template<typename T1,typename T2>void rd(pair<T1,T2>&x){rd(x.first);rd(x.second);}
template<typename T>void rd(vector<T>&x){for(T&i:x)rd(i);}
template<typename T,typename...A>void rd(T&x,A&...args){rd(x);rd(args...);}
template<typename T>void rd(){T x;rd(x);return x;}
int ri(){int x;rd(x);return x;}
template<typename T>vector<T> rv(int n){vector<T> x(n);rd(x);return x;}
template<typename T>void ra(T a[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]);}
template<typename T1,typename T2>void ra(T1 a[],T2 b[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]);}
template<typename T1,typename T2,typename T3>void ra(T1 a[],T2 b[],T3 c[],int n,int st=1){for(int i=0;i<n;++i)rd(a[st+i]),rd(b[st+i]),rd(c[st+i]);}
void re(vector<int> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){rd(u,v);E[u].pb(v);if(!dir)E[v].pb(u);}}
template<typename T>void re(vector<pair<int,T>> E[],int m,bool dir=0){for(int i=0,u,v;i<m;++i){T w;rd(u,v,w);E[u].pb({v,w});if(!dir)E[v].pb({u,w});}}

const int N=100050;
char s[N];
int idx;
void put(int i){
    s[++idx]='a'+i;
}
int main(){
    for(int t=ri();t--;){
        scanf("%s",s+1);
        int n=strlen(s+1);
        vector<int> cnt(26,0);
        int mn=26;
        for(int i=1;i<=n;i++){
            cnt[s[i]-'a']++;
            ckmn(mn,s[i]-'a');
        }
        int lo=-1;
        for(int i=0;i<26;i++){
            if(cnt[i]==1){
                lo=i;
                break;
            }
        }
        idx=0;
        if(lo!=-1){
            put(lo);
            cnt[lo]--;
            for(int i=0;i<26;i++){
                while(cnt[i]>0){
                    put(i);
                    cnt[i]--;
                }
            }
        }else if(cnt[mn]==1||cnt[mn]==n){
            sort(s+1,s+1+n);
        }else if(cnt[mn]>(n-cnt[mn])+2){
            put(mn);
            cnt[mn]--;
            vector<int> other;
            for(int i=mn+1;i<26;i++){
                while(cnt[i]>0){
                    other.pb(i);
                    cnt[i]--;
                }
            }
            put(other[0]);
            if(other.back()==other.front()){
                for(int i=1;i<other.size();i++){
                    put(other[i]);
                }
                while(cnt[mn]){
                    put(mn);
                    cnt[mn]--;
                }
            }else{
                while(cnt[mn]){
                    put(mn);
                    cnt[mn]--;
                }
                int fir=0;
                for(int i=1;i<other.size();i++){
                    if(other[i]!=other[0]){
                        fir=i;
                        break;
                    }
                }
                put(other[fir]);
                for(int i=1;i<other.size();i++){
                    if(i!=fir){
                        put(other[i]);
                    }
                }
            }
        }else{
            put(mn);
            put(mn);
            cnt[mn]-=2;
            vector<int> other;
            for(int i=mn+1;i<26;i++){
                while(cnt[i]>0){
                    other.pb(i);
                    cnt[i]--;
                }
            }
            for(int i=0;i<other.size();i++){
                put(other[i]);
                if(cnt[mn]){
                    put(mn);
                    cnt[mn]--;
                }
            }
        }
        printf("%s\n",s+1);
    }
	return 0;
}