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
const int MAXN = 1000007;

int n;
bool isp[MAXN];

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

	INIT ( isp, true );
	isp[0] = isp[1] = false;
	lp ( i, 2, MAXN ) {
		if ( isp[i] ) {
			for ( int j = i << 1; j < MAXN; j += i ) isp[j] = false;
		}
	}
}

void input ()
{
	// input method

	cin >> n;
}

void work ()
{
	// main work

	int nl, nr;

	lpd ( i, n, 0 ) {
		if ( isp[i] && ( n % i == 0 ) ) {
			nl = ( n - n / ( n / i ) + 1 ), nr = n;
			break;
		}
	}

	int ans = INF, cd;
	lpi ( i, 1, n ) {
		if ( isp[i] ) {
			cd = ( nl + i - 1 ) / i;
			if ( cd > 1 && i * cd <= nr ) {
				ans = qmin ( ans, i * cd - i + 1 );
			}
		}
	}

	cout << ans << endl;
}