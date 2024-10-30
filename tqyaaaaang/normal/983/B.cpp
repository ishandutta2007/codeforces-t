#include <bits/stdc++.h>
using namespace std;

#define LL long long
#define LD long double
#define SC(t,x) static_cast<t>(x)
#define AR(t) vector < t >
#define PII pair < int, int >
#define PLL pair < LL, LL >
#define PIL pair < int, LL >
#define PLI pair < LL, int >
#define MP make_pair
#define PB push_back
#define PF push_front
#define POB pop_back
#define POF pop_front
#define PRF first
#define PRS second
#define INIT(ar,val) memset ( ar, val, sizeof ( ar ) )
#define lp(loop,start,end) for ( int loop = start; loop < end; ++loop )
#define lpd(loop,start,end) for ( int loop = start; loop > end; --loop )
#define lpi(loop,start,end) for ( int loop = start; loop <= end; ++loop )
#define lpdi(loop,start,end) for ( int loop = start; loop >= end; --loop )
#define qmax(a,b) (((a)>(b))?(a):(b))
#define qmin(a,b) (((a)<(b))?(a):(b))
#define qabs(a) (((a)>=0)?(a):(-(a)))

const int INF = 0x3fffffff;
const int SINF = 0x7fffffff;
const long long LINF = 0x3fffffffffffffff;
const long long SLINF = 0x7fffffffffffffff;
const int MAXN = 5007;

int n, q;
int a[MAXN];
int ps[MAXN];
int val[MAXN][MAXN];
int dp[MAXN][MAXN];

void init ();
void input ();
void work ();



int main ()
{
	init ();
	input ();
	work ();
}



void init ()
{
	// Init Everything Here

	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%d", &n );
	lpi ( i, 1, n ) scanf ( "%d", &a[i] );
	scanf ( "%d", &q );
}

void work ()
{
	// main work

	lpi ( i, 1, n ) val[i][i] = a[i], dp[i][i] = a[i], ps[i] = ps[i - 1] ^ a[i];
	lpi ( d, 2, n ) {
		lpi ( i, 1, n - d + 1 ) {
			val[i][i + d - 1] = val[i][i + d - 2] ^ val[i + 1][i + d - 1];
			dp[i][i + d - 1] = max ( qmax ( dp[i][i + d - 2], dp[i + 1][i + d - 1] ), val[i][i+d-1] );
		}
	}

	int l, r;
	lp ( _q, 0, q ) {
		scanf ( "%d%d", &l, &r );
		printf ( "%d\n", dp[l][r] );
	}
}