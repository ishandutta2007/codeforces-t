#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define ll long long
#define mt make_tuple
#define ldb double
#define pii pair<int,int>
#define pll pair<ll,ll>
template<typename T>void ckmn(T &a,T b){a=min(a,b);}
template<typename T>void ckmx(T &a,T b){a=max(a,b);}
int ri(){int x;scanf("%i",&x);return x;}
void rd(){}
template<typename...T>void rd(int &x,T&...args){scanf("%i",&x);rd(args...);}
template<typename...T>void rd(ll &x,T&...args){scanf("%lld",&x);rd(args...);}
template<typename...T>void rd(ldb &x,T&...args){scanf("%lf",&x);rd(args...);}
template<typename...T>void rd(pii &x,T&...args){scanf("%i %i",&x.first,&x.second);rd(args...);}

int main(){
	for(int t=ri();t--;){
		int n=ri();
		vector<int> a(n);
		for(int &i:a)rd(i);
		vector<int> b(n);
		for(int &i:b)rd(i);
		bool srt=1,dif=0;
		for(int i=1;i<n;i++){
			if(a[i]<a[i-1])srt=0;
			if(b[i]!=b[i-1])dif=1;
		}
		if(srt||dif)printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}