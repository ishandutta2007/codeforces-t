/*----------------by syr----------------*/
/*

         iii                  ii
     rBQBBBBBBE       BBR iBBBBQBBL     XBBBBBBQBBBBB
   iBBQJ    7BBB      BBsSBBr   BBQ      i      cBBB
  rBBU       iBBw     BBBQi     HBBi           KBBi
  BBH         BB5    iBBB       isL          wBB5
 GBB         iBBi    6BB                   iBBB
 BBQ         BQB     BBD                  QBBi
 BBB        BQB     iQBi                1BBv
 sBBg     wBBB      QBB               iBBB
  7BBBBBBBBBi       BBR              wBBBBBBBBBBBBB
     irvi           ii               ii    i i iii
                i5U
               BBB
               BB7
              1BB
      iPBBBBBKBBR    JBR1       rQBO   BR  UBQP  iBBQi
    7BBBGs7sXBBBi     QBBr     gBBE   rBB BB2BB7HBZQBB
   QBBi      sBQ       BBB   iBBB     SQBBR  BBBB  cBQ
  gBQ        BBg        BBB KBBi      MBBH   BBB   BBs
 iBBv       iBBi         QBBBL        BBR   pBB   iBB
 pBB        BBB         iBBBB        iBB    BBL   KBB
 MBB       BBBR        BBB JBBi      DBR   iBQ    BBL
 GBB     7BBBB2      PBBH   BBBi     BQr   DBB   iBB
  BQBXwgBBP BB7    1BBB      BBQ7   1BB    BBc   BBB
   2BBBBw   BB    EBBS        QBBi  HBa   iBB    BB7
*/
#include<bits/stdc++.h>

using namespace std;

#define PH push
#define MP make_pair
#define PB push_back
#define fst first
#define snd second
#define FOR(i, x, y) for(int i = (x); i < (y); ++i)
#define REP(i, x, y) for(int i = (x); i <= (y); ++i)
#define x0 x0123456789
#define y0 y0123456789
#define x1 x1234567890
#define y1 y1234567890
#define x2 x2345678901
#define y2 y2345678901
typedef double db;
typedef long long ll;
typedef long double ldb;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

const int INF = 1e9 + 7;
const int maxn = 150;

int T;
int n, m1, m2;
int cnt[maxn];
char s[maxn], ans1[maxn], ans2[maxn];

void solve(){
	memset(cnt, 0, sizeof(cnt));
	memset(ans1, 0, sizeof(ans1));
	memset(ans2, 0, sizeof(ans2));
	m1 = m2 = 0;
	scanf("%s", s);
	n = strlen(s);
	FOR(i, 0, n)
		++cnt[s[i]];
	bool odd = true, even = true;
	REP(i, 'a', 'z'){
		if((i & 1) && cnt[i])
			odd = false;
		if(!(i & 1) && cnt[i])
			even = false;
	}
	if(odd || even){
		printf("%s\n", s);
		return;
	}
	REP(i, 'a', 'z') if(((i - 'a') & 1) && cnt[i]){
		REP(j, 'a', 'z') if(!((j - 'a') & 1) && cnt[j] && abs(i - j) != 1){
			REP(k, 'a', 'z')
				if(((k - 'a') & 1) && k != i)
					FOR(l, 0, cnt[k])
						ans1[m1++] = k;
				else if(!((k - 'a') & 1) && k != j)
					FOR(l, 0, cnt[k])
						ans2[cnt[j] + m2 ] = k, m2++;
			FOR(k, 0, cnt[i])
				ans1[m1++] = i;
			FOR(k, 0, cnt[j])
				ans2[k] = j;
			printf("%s%s\n", ans1, ans2);
			return;
		}
	}
	puts("No answer");
}

int main(){
	scanf("%d", &T);
	for(; T--; solve());
	return 0;
}