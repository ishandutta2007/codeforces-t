#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define MOD			1000000007
#define FOR(i,l,r)	for(int i=l;i<=r;i++)
#define REP(i,n)	for(int i=1;i<=n;i++)
#define REP0(i,n)	for(int i=0;i<n;i++)
#define PB			push_back
#define MP			make_pair
#define PII			pair<int,int>
#define VI			vector<int>
#define ALL(x)		(x).begin(),(x).end()
#define MAKE1(a)	int a;
#define MAKE2(a,b)	int a,b;
#define MAKE3(a,b,c) int a,b,c;
#define MAKE4(a,b,c,d) int a,b,c,d;
#define DR1(a)		MAKE1(a);cin>>a;
#define DR2(a,b)	MAKE2(a,b);cin>>a>>b;
#define DR3(a,b,c)	MAKE3(a,b,c);cin>>a>>b>>c;
#define DR4(a,b,c,d) MAKE4(a,b,c,d);cin>>a>>b>>c>>d;
#define int long long
int n,k,mx=1,a[400005],b[400005],cnt=0,ans=INT_MAX;
signed main(){
	cin>>n>>k;
	k*=8;
	k=k/n;
	for(int i=1;i<=k;i++){
		if(mx<n)	mx=mx*2;
	}
	if(mx>n)	mx=n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=a[i-1])	b[i]=b[i-1]+1,cnt++;
		else				b[i]=b[i-1];
//		cout<<b[i]<<" ";
	}
	if(cnt<=mx){
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++){
		int ind=lower_bound(b+1,b+1+n,b[i]+mx)-b;
		if(ind>n)	ind=n+1;
//		cout<<ind<<endl;
		ind--;
		ans=min(ans,i-1+n-ind);
	}
	cout<<ans<<endl;
	return 0;
}