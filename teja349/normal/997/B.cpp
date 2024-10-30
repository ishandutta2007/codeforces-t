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
ll dp[212345],visit[212345]; 
ll compute(int val){
	if(val<0)
		return inf;
	if(visit[val])
		return dp[val];
	visit[val]=1;
	//int mini=inf;
	dp[val]=compute(val-4)+1;
	dp[val]=min(dp[val],compute(val-9)+1);
	dp[val]=min(dp[val],compute(val-49)+1);
	return dp[val];
}
ll compute1(int val){
	if(val<0)
		return inf;
	if(visit[val])
		return dp[val];
	visit[val]=1;
	//int mini=inf;
	dp[val]=compute(val-40)+1;
	dp[val]=min(dp[val],compute(val-45)+1);
	dp[val]=min(dp[val],compute(val-49)+1);
	return dp[val];
}
int main(){
    std::ios::sync_with_stdio(false);
    ll n;
    cin>>n;
    dp[0]=0;
    visit[0]=1;
    ll i,ans=1;
    f(i,1,123456){
    	compute(i);
    	if(dp[i]<=n){

    		ans++;
    	}
    }
    ll maxi=49L*n;
    dp[0]=0;
    visit[0]=1;
    if(maxi>=123456)
    	ans++;
    f(i,1,123456){
    	visit[i]=0;
    	if(maxi-i<123456)
    		break;
    	compute1(i);
    	if(dp[i]<=n){

    		ans++;
    	}
    }

    maxi-=123456;
    
    if(maxi>=123455){
    	ans+=maxi-123455;
    }
    cout<<ans<<endl;

    return 0;  
    
}