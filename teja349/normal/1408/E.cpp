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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val

using namespace std;
using namespace __gnu_pbds;

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

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
#define int ll

int dsu[212345];
int getpar(int u){
	if(dsu[u]<0)
		return u;
	dsu[u]=getpar(dsu[u]);
	return dsu[u];
}

int merge(int u,int v){
	u=getpar(u);
	v=getpar(v);
	if(dsu[u]<dsu[v])
		swap(u,v);
	dsu[v]+=dsu[u];
	dsu[u]=v;
	return 0;
}
int a[123456],b[123456];

main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int m,n;
    cin>>m>>n;
    int i,j;
    rep(i,m){
    	cin>>a[i];
    }
    rep(i,n){
    	cin>>b[i];
    }
    rep(i,n+m+10){
    	dsu[i]=-1;
    }
    viii vec;
    int tot=0;
    int sz,x;
    rep(i,m){
    	cin>>sz;
    	rep(j,sz){
    		cin>>x;
    		x--;	
    		vec.pb(mp(a[i]+b[x],mp(i+n,x)));
    	}
    }
    sort(all(vec));
    sz=vec.size();
    int u,v;
    fd(i,sz-1,0){
    	u=vec[i].ss.ff;
    	v=vec[i].ss.ss;
    	if(getpar(u)==getpar(v)){
    		tot+=vec[i].ff;
    		continue;
    	}
    	merge(u,v);
    }
    cout<<tot<<endl;

}