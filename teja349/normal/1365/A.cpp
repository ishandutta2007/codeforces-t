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

int a[123][123];
int main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
    	int n,m;
    	cin>>n>>m;
    	int i,j;
    	rep(i,n){
    		rep(j,m){
    			cin>>a[i][j];
    		}
    	}
    	int row=0,col=0,flag=0;
    	rep(i,n){
    		flag=1;
    		rep(j,m){
    			if(a[i][j]==1)
    				flag=0;
    		}
    		row+=flag;
    	}
    	rep(j,m){
    		flag=1;
    		rep(i,n){
    			if(a[i][j]==1)
    				flag=0;
    		}
    		col+=flag;
    	}
    	row=min(row,col);
    	if(row%2){
    		cout<<"Ashish"<<endl;
    	}
    	else{
    		cout<<"Vivek"<<endl;
    	}
    }
    return 0;   
}