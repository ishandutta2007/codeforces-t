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
int a[123][123];
int lol[123456],n;
int check(int p,int q){
	int i;
	rep(i,n){
		if(a[p][q]-a[i][q]>0 && lol[a[p][q]-a[i][q]]!=0)
			return 1;
	}
	return 0;
}
int main(){
    std::ios::sync_with_stdio(false);
    //int n;
    cin>>n;
    int i,j;
    rep(i,n){
    	
    	rep(j,n){
    		cin>>a[i][j];
    	}


    }
    rep(i,n){
    	rep(j,n){
    		lol[a[i][j]]=1;
    	}
    	rep(j,n){
    		if(a[i][j]!=1){
    			if(!check(i,j))
    			{
    				cout<<"No"<<endl;
    				return 0;
    			}
    		}
    	}
    	rep(j,n){
    		lol[a[i][j]]=0;
    	}
    }
    cout<<"Yes"<<endl;
    
}