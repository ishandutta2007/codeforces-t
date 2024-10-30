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
int arr[1234][1234];
int main(){
    std::ios::sync_with_stdio(false);
    int n,a,b;
    cin>>n>>a>>b;
    if(n==1){
    	cout<<"YES"<<endl;
    	cout<<0<<endl;
    	return 0;
    }
    int i,j;
    if(n==2){
    	if(a+b==3){
    		cout<<"YES"<<endl;
    		if(a==1){
    			cout<<"01"<<endl<<"10"<<endl;
    		}
    		else{
    			cout<<"00"<<endl<<"00"<<endl;
    		}
    	}
    	else{
    		cout<<"NO"<<endl;
    	}
    	return 0;
    }
    if(n==3 && a+b==2){
    	cout<<"NO"<<endl;
    	return 0;
    }
   	if(a!=1 && b!=1){
   		cout<<"NO"<<endl;
   		return 0;
   	}
   	int flag=0;
   	if(a==1){swap(a,b);
   		flag=1;}

   	f(i,a-1,n-1){
   		arr[i][i+1]=1;
   		arr[i+1][i]=1;
   	}
   	rep(i,n){
   		rep(j,n){
   			if(i!=j && flag){
   				arr[i][j]^=1;
   			}
   		}
   	}
   	cout<<"YES"<<endl;
   	rep(i,n){
   		rep(j,n){
   			cout<<arr[i][j];
   		}
   		cout<<endl;
   	}
   	return 0;
    return 0;  
    
}