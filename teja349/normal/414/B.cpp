
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
ll a[2003][2003]={0};

ll update(int j,int i,int n);
int main(){
	int n,k,i,j;
	cin>>n>>k;
	f(i,1,n+1){
		a[i][1]=1;
		//cout<<"hii";
		//cout<<a[1][1]<<endl;
	}
	f(j,1,k){
		f(i,1,n+1){
			update(j,i,n);
		}
	}
	ll sum=0;
	f(i,1,n+1){
		sum+=a[i][k];
		sum%=mod;
	}
	cout<<sum<<endl;

}
ll update(int j,int i,int n){
	int k;
	for(k=i;k<n+1;k+=i){
		a[k][j+1]+=a[i][j];
		a[k][j+1]%=mod;
	}
}