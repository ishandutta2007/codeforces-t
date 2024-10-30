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
int bit[123456];
int total=0;
int query(int val){
	int ans=0;
	while(val>0){
		ans+=bit[val];
		val-=val&(-val);
	}
	return total-ans;
}
int update(int val){
	while(val<123456){
		bit[val]++;
		val+=val&(-val);
	}
	total++;
	return 0;
}
int p[123456],haha[123456];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,val;
    set<int> seti;
    set<int>::iterator it;
    rep(i,n){
    	cin>>p[i];
    	val=query(p[i]);
    	if(val==1){
    		it=seti.upper_bound(p[i]);
    		haha[*it]++;
    	}
        if(val==0){
            haha[p[i]]--;
        }
    	update(p[i]);
    	seti.insert(p[i]);
    }
    int mini=-10;
    val=1;
    f(i,1,n+1){
    	if(haha[i]>mini){
    		mini=haha[i];
    		val=i;
    	}
    }
    cout<<val<<endl;
    return 0;  
    
}