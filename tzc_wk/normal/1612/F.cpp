#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
template <typename T1, typename T2> void chkmin(T1 &x, T2 y){
	if (x > y) x = y;
}
template <typename T1, typename T2> void chkmax(T1 &x, T2 y){
	if (x < y) x = y;
}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
namespace fastio {
	#define FILE_SIZE 1 << 23
	char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
	inline char getc() {
		return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1: *p1++;
	}
	inline void putc(char x) {(*p3++ = x);}
	template <typename T> void read(T &x) {
		x = 0; char c = getchar(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getchar();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getchar();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x<0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 2e5;
const int MAXC = 40;
int n, m, qu;
vector<int> dp[MAXN + 5];
map<int, bool> is[MAXN + 5];
int main() {
	scanf("%d%d%d", &n, &m, &qu);
	for (int i = 1, x, y; i <= qu; i++) {
		scanf("%d%d", &x, &y);
		if (n > m) swap(x, y);
		is[x][y] = 1;
	}
	if (n > m) swap(n, m);
	int lim = m / n + MAXC;
//	printf("%d\n", lim);
	for (int j = 1; j <= n; j++) dp[j].resize(lim + 1);
	dp[1][0] = 1;
	for (int i = 0; i < lim; i++) for (int j = 1; j <= n; j++) {
		if (dp[j][i]) {
			chkmax(dp[j][i + 1], min(j + dp[j][i] + is[j][dp[j][i]], m));
			chkmax(dp[min(j + dp[j][i] + is[j][dp[j][i]], n)][i + 1], dp[j][i]);
		}
	}
	for (int i = 0; i <= lim; i++) if (dp[n][i] == m)
		return printf("%d\n", i), 0;
	return 0;
}