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
set<ll> seti;
int main(){
	std::ios::sync_with_stdio(false);
	ll b,q,l,m,i,val,lol;
	cin>>b>>q>>l>>m;
	rep(i,m){
		cin>>val;
		seti.insert(val);
	}
	lol=0;
	if(q==0){
		if(abs(b)>l){
			cout<<0<<endl;
			return 0;
		}
		if(seti.find(b)==seti.end()){
			lol++;
		}
		if(seti.find(0)!=seti.end()){
			cout<<lol<<	endl;
		}
		else{
			cout<<"inf"<<endl;
			//return 0;
		}
		return 0;
	}
	if(q==1){
		
		if(seti.find(b)==seti.end() && abs(b)<=l){
			cout<<"inf"<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(q==-1){
		if(seti.find(b)==seti.end() && abs(b)<=l){
			cout<<"inf"<<endl;
		}
		else if(seti.find(-b)==seti.end() && abs(b)<=l){
			cout<<"inf"<<endl;
		}
		else{
			cout<<0<<endl;
		}
		return 0;
	}
	if(b==0){
		lol=0;
		if(seti.find(0)!=seti.end()){
			cout<<lol<<endl;
		}
		else{
			cout<<"inf"<<endl;
			return 0;
		}
		return 0;
	}
	ll ans=0;
	while(abs(b)<=l){
		if(seti.find(b)==seti.end())
			ans++;
		b*=q;
	}
	cout<<ans<<endl;
	return 0;



}