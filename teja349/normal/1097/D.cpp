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
#define int ll



// ll inv[100003],mult[100003],invmult[100003];
// ll gcd(ll a,ll b){
// 	while(b!=0){
		
// 		a=a%b;
// 		swap(a,b);
// 	}
// 	return a;
// }

// ll extend_gcd(ll a,ll b,ll &x,ll &y){
// 	if(b==0){
// 		x=1;
// 		y=0;
// 		return a;
// 	}
// 	ll x1,y1;
// 	ll ans =extend_gcd(b,a%b,x1,y1);
// 	x=y1;
// 	y=x1-(a/b)*y1;

// 	return ans;
// }

// ll combination(ll n,ll r){
// 	if(r==0)
// 		return 1;
// 	if(n<r)
// 		return 0;
// 	ll ans=1;
// 	ans*=mult[n];
// 	ans%=mod;
// 	ans*=invmult[r];
// 	ans%=mod;
// 	ans*=invmult[n-r];
// 	ans%=mod;
// 	return ans;
// }

// ll initcombi(){
// 	int i;
// 	f(i,1,100001){
// 		ll x,y;
// 		ll val=extend_gcd(mod,i,x,y);
// 		if(y>0)
// 			inv[i]=y%mod;
// 		else{
// 				inv[i]=(y+mod)%mod;
// 		}
// 	}
// 	mult[0]=1;
// 	f(i,1,100001){
// 		mult[i]=mult[i-1]*i;
// 		mult[i]%=mod;
// 	}
// 	invmult[0]=1;
// 	f(i,1,100001){
// 		invmult[i]=invmult[i-1]*inv[i];
// 		invmult[i]%=mod;
// 	}
// 	return 0;
// }
int getpow(int a,int b){
	int ans=1;
	while(b>0){
		if(b%2){
			ans*=a;
			ans%=mod;
		}
		a*=a;
		a%=mod;
		b/=2;
	}
	return ans;
}

// do initcombi();
int p1[1234],p2[1234];
int lol;
vii vec;
map<int,int> mapi;
int ans=0;
int k;
int inv[1234],boo[1234];
int compute(int pos,int val,int prob){
	//cout<<pos<<" "<<val<<endl;
	if(pos==lol){
		//cout<<val<<endl;
		ans+=prob*val;
		ans%=mod;
		return 0;
	}
	int gg=vec[pos].ss;
	int haha=vec[pos].ff;
	haha%=mod;
	int pp;
	int i;
	//cout<<gg<<endl;
	rep(i,gg+1){
		boo[i]=0;
	}
	boo[gg]=1;
	int val1;
	int j;
	rep(i,k){
		rep(j,gg+1){
			val1=inv[j+1];
			val1*=boo[j];
			val1%=mod;
			boo[j]=0;
			rep(pp,j+1){
				boo[pp]+=val1;
				boo[pp]%=mod;
			}
		}
	}
	rep(i,gg+1){
		//pp=combination(gg,i)*p1[gg-i];
		pp=boo[i];
		pp*=prob;
		pp%=mod;
		compute(pos+1,val,pp);
		val*=haha;
		val%=mod;
	}
	return 0;
	
}
signed main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
    //initcombi();
  	int n,i;
  	cin>>n>>k;
  	// p1[0]=1;
  	// p2[0]=1;
  	// p2[1]=getpow(2,k);
  	// p2[1]=getpow(p2[1],mod-2);
  	
  	// p1[1]=1-p2[1];
  	// p1[1]%=mod;
  	// p1[1]+=mod;
  	// p1[1]%=mod;
  	inv[1]=1;

  	f(i,2,123){
  		inv[i]=getpow(i,mod-2);
  		// p2[i]=p2[i-1]*p2[1];
  		// p2[i]%=mod;
  		// p1[i]=p1[i-1]*p1[1];
  		// p1[i]%=mod;
  	}
  	for(i=2;i*i<=n;i++){
  		while(n%i==0){
  			mapi[i]++;
  			n/=i;
  		}
  	}
  	if(n!=1){
  		mapi[n]++;
  	}
  	ll bigg=1;
  	map<int,int>::iterator it;
  	lol=1;
  	for(it=mapi.begin();it!=mapi.end();it++){
  		vec.clear();
  		ans=0;
  		vec.pb(mp(it->ff,it->ss));
  		compute(0,1,1);
  		bigg*=ans;
  		bigg%=mod;
  	}
  	cout<<bigg<<endl;
  	
  	//cout<<lol<<endl;
  
    return 0;   
}