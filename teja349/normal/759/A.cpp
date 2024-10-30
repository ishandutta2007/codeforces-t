
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
//setprecision - cout << setprecision (4) << f << endl; Prints x.xxxx


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
int visit[300000]={0};
int a[300000],b[300000]; 
int dfs(int i){
	if(visit[i]==1)
		return 0;
	visit[i]=1;
	return 1+dfs(a[i]);

}
int main(){
	std::ios::sync_with_stdio(false);
	int n,i;
	cin>>n;
	f(i,1,n+1){
		cin>>a[i];
	}
	int sumi=0,counti=0,cycle=0;
	f(i,1,n+1){
		cin>>b[i];
		if(b[i]!=0)
			counti++;
	}
	if(counti%2==0){
		sumi+=1;
	}
	f(i,1,n+1){
		if(!visit[i]){
			cycle++;
			dfs(i);
		}
	}
	if(cycle==1){
		cout<<sumi<<endl;
	}
	else{
		cout<<cycle+sumi<<endl;
	}
}