#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stdlib.h>
#include <ctime>
#include <cmath>
#include <complex>
#include <iostream>
#include <cctype>
#include <cstring>
#include <bitset>
#include <stack>
#include <functional>
#include <cassert>
#include <tuple>
#include <iomanip>
using namespace std;
#define ll long long
#define mp make_pair
#define pb push_back
#define ldb long double
#define mt make_tuple
template<typename T> bool ckmn(T &a, T b){ T c=a;a=min(a,b);return a!=c;}
template<typename T> bool ckmx(T &a, T b){ T c=a;a=max(a,b);return a!=c;}

int main(){
	int t;scanf("%i",&t);
	while(t--){
		int n;scanf("%i",&n);
		vector<int> a(n),b(n);
		for(int &i:a)scanf("%i",&i);
		for(int &i:b)scanf("%i",&i);
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		for(int i:a)printf("%i ",i);printf("\n");
		for(int i:b)printf("%i ",i);printf("\n");
	}
	return 0;
}