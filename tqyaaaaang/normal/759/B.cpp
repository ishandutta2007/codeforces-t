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
const int MAXN = 100007;

int n;
int t[MAXN];
int dp[MAXN];

void init ();
void input ();
void work ();



int main()
{
	init();
	input();
	work();
}



void init ()
{
	// Init Everything Here
	
	ios::sync_with_stdio ( false );
}

void input ()
{
	// input method

	scanf ( "%d" ,&n );
	lpi ( i, 1, n ) scanf ( "%d", &t[i] );
}

void work ()
{
	// main work

	INIT ( dp, 111111 );
	dp[0] = 0;
	int t1, t2, tt;
	lp ( i, 0, n ){
		dp[i+1] = qmin ( dp[i+1], dp[i] + 20 );
		t1 = dp[i] + 50, t2 = dp[i] + 120;
		tt = t[i+1];
		lpi ( j, i+1, n ){
			if ( t[j] - tt < 90 ) dp[j] = qmin ( dp[j], t1 );
			else if ( t[j] - tt < 1440 ) dp[j] = qmin ( dp[j], t2 );
			else break;
		}
	}

	lpi ( i, 1, n ) printf ( "%d\n", dp[i] - dp[i-1] );
}