#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <utility>
#include <queue>
#include <stack>
#include <functional>
#include <set>
#include <map>
#include <cassert>
#include <cmath>
#include <cstdlib>

using namespace std;
typedef long long lli;
typedef pair<int,int> ip;
typedef pair<lli,int> lip;
typedef pair<lli,lli> llp;

inline double POWER(double a) {return a*a;}
inline lli _abs(lli a) {return a<0?-a:a;}
inline int _abs(int a) {return a<0?-a:a;}
inline lli power(lli a) { return a*a; }
inline int power(int a) { return a*a; }
inline lli gcd(lli a,lli b) {while(b) {lli tmp=a%b;a=b;b=tmp;}return a;}
inline int gcd(int a,int b) {while(b) {int tmp=a%b;a=b;b=tmp;}return a;}
const double EPS=1e-9;
const int mod=9901;
const lli inf=3e15;
const int dy[4]={0,-1,0,1},dx[4]={1,0,-1,0};
const double PI=acos(-1);
const char DC[4]={'E','N','W','S'};

int main() {
	int a,b;
	scanf("%d%d",&a,&b);
	if(a==b||b==0) printf("0 ");
	else printf("1 ");
	

	lli bb=b;
	lli xx=2+3*(bb-1);
	if(xx+1>=a) {
		printf("%d\n",a-b);
	}
	else {
		printf("%lld\n",(xx+1)-b);
	}

	return 0;
}