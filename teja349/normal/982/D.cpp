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

//std::ios::sync_with_stdio(false); 
int dsu[123456];
int a[123456];
multiset<int> seti;
multiset<int>::iterator it,it1; 
int getpar(int u){
	if(dsu[u]<0)
		return u;
	dsu[u]=getpar(dsu[u]);
	return dsu[u];
} 
int getsum(int u){
	return -1*dsu[getpar(u)];
}
int merge(int u,int v){
	u=getpar(u);
	v=getpar(v);
	if(dsu[u]<dsu[v]){
		swap(u,v);
	}
	dsu[v]+=dsu[u];
	dsu[u]=v;
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i;
    vii vec;
    f(i,1,n+1){
    	cin>>a[i];
    	vec.pb(mp(a[i],i));
    	dsu[i]=-1;
    }
    a[n+1]=inf;
    a[0]=inf;
    sort(all(vec));
    seti.insert(1);
    int loca=1;
    int val,haha,flag,k=vec[0].ff+1;
    f(i,1,vec.size()){
    	//cout<<i<<"dsad"<<endl;
    	val=vec[i].ss;
    	haha=vec[i].ff+1;
    	val=i;
    	i=vec[i].ss;
    	seti.insert(1);
    	flag=0;
    	if(a[i+1]<haha){
    		seti.erase(seti.find(getsum(i+1)));
    		seti.erase(seti.find(getsum(i)));
    		merge(i+1,i);
    		seti.insert(getsum(i));
    	
    	}
    	else{
    		flag++;
    	}
    	if(a[i-1]<haha){
    		seti.erase(seti.find(getsum(i-1)));
    		seti.erase(seti.find(getsum(i)));
    		merge(i-1,i);
    		seti.insert(getsum(i));
    	}
    	else{
    		flag++;
    	}
    	
    	it=seti.begin();
    	it1=seti.end();
    	it1--;
    	if(*it==*it1){
    		if(loca<seti.size()){
    			k=haha;
    			loca=seti.size();
    		}
    		

    	}
    	//cout<<
    	i=val;
    }
    cout<<k<<endl;

    return 0;  
    
}