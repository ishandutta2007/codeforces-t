#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast < t > ( x )
#define AR(x) vector < x >
#define lp(loop,begin,end) for ( int loop = begin; loop < end; loop++ )

const int INF = 0x3fffffff;

int main()
{
	ios::sync_with_stdio ( false );

	int n, now = 0, t;
	LL cc = 0;

	cin >> n;
	lp ( i, 0, n ){
		cin >> t;

		cc += abs ( t - now );
		now = t;
	}

	cout << cc << endl;
}