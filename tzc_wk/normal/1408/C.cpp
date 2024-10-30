/*
Contest: Grakn Forces 2020
Problem: Codeforces 1408C
Author: tzc_wk
Time: 2020.9.30
*/
#include <bits/stdc++.h>
using namespace std;
#define fi			first
#define se			second
#define pb			push_back
#define fz(i,a,b)	for(int i=a;i<=b;i++)
#define fd(i,a,b)	for(int i=a;i>=b;i--)
#define foreach(it,v) for(__typeof(v.begin()) it=v.begin();it!=v.end();it++)
#define all(a)		a.begin(),a.end()
#define fill0(a)	memset(a,0,sizeof(a))
#define fill1(a)	memset(a,-1,sizeof(a))
#define fillbig(a)	memset(a,0x3f,sizeof(a))
#define y1			y1010101010101
#define y0			y0101010101010
typedef pair<int,int> pii;
typedef long long ll;
inline int read(){
	int x=0,neg=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-') neg=-1;
		c=getchar();
	}
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	return x*neg;
}
int n,l,a[100005];
inline void solve(){
	n=read();l=read();fz(i,1,n) a[i]=read();
	double xa=0,xb=l,t=0;
	int nxta=1,nxtb=n,va=1,vb=1;
	while(nxta!=nxtb+1){
		double ta=1.0*(a[nxta]-xa)/va;
		double tb=1.0*(xb-a[nxtb])/vb;
		if(ta<tb){
			xa=a[nxta];nxta++;va++;t+=ta;
			xb-=vb*ta;
		}
		else{
			xb=a[nxtb];nxtb--;vb++;t+=tb;
			xa+=va*tb;
		}
	}
	printf("%.10lf\n",t+1.0*(xb-xa)/(vb+va));
}
int main(){
	int T=read();
	while(T--) solve();
	return 0;
}