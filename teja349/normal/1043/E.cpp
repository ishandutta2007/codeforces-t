//teja349
#include <bits/stdc++.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
#define int ll
int x[312345],y[312345],ans[312345];
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int n,m;
    cin>>n>>m;
    int i,j;
    int sumi=0;
    vll vec;
    rep(i,n){
    	cin>>x[i]>>y[i];
    	sumi+=y[i];
    	vec.pb(mp(x[i]-y[i],i));
    }
    rep(i,n){
    	ans[i]=y[i]*(n-1)+sumi-y[i];
    }
    sort(all(vec));
    ll gg=0;
    int u,v;
    rep(i,n){
    	u=vec[i].ss;
    	ans[u]+=gg;
    	ans[u]+=(n-1-i)*(x[u]-y[u]);
    	gg+=vec[i].ff;
    }
    rep(i,m){
    	cin>>u>>v;
    	u--;
    	v--;
    	ans[u]-=y[u]+y[v]+min(x[u]-y[u],x[v]-y[v]);
    	ans[v]-=y[u]+y[v]+min(x[u]-y[u],x[v]-y[v]);
    }
    rep(i,n){
    	cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;   
}