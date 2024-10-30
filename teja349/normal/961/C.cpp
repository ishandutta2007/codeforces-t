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
string a[5][123];
int boo[1234];
int zero[12],one[12];
int main(){
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int i,j,k;
    rep(k,4){
    	rep(i,n){
    		cin>>a[k][i];
    	}
    	rep(i,n){
    		rep(j,n){
    			if((i+j)%2){
    				if(a[k][i][j]=='1'){
    					zero[k]++;
    				}
    				else{
    					one[k]++;
    				}
    			}
    			else{
    				if(a[k][i][j]=='0'){
    					zero[k]++;
    				}
    				else{
    					one[k]++;
    				}
    			}
    			
    		}
    	}
    }
    //return 0;
    rep(i,4){
    	boo[i]=i;
    }
    int ans=0;
    int mini=inf;
    while(1){
    	ans=0;
    	rep(i,4){
    		if(i<2){
    			ans+=zero[boo[i]];
    		}
    		else
    			ans+=one[boo[i]];
    	}
    	mini=min(mini,ans);
    	if(!next_permutation(boo,boo+4))
    		break;
    }
    cout<<mini<<endl;

    return 0;  
    
}