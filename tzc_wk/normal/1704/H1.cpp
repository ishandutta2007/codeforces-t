#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
using namespace std;
// using namespace __gnu_pbds;
#define fi first
#define se second
#define fill0(a) memset(a, 0, sizeof(a))
#define fill1(a) memset(a, -1, sizeof(a))
#define fillbig(a) memset(a, 63, sizeof(a))
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define mt make_tuple
#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 1064
#endif
template<typename T1, typename T2> void chkmin(T1 &x, T2 y) {if (x > y) x = y;}
template<typename T1, typename T2> void chkmax(T1 &x, T2 y) {if (x < y) x = y;}
typedef pair<int, int> pii;
typedef long long ll;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef long double ld;
#ifdef FASTIO
#define FILE_SIZE 1 << 23
char rbuf[FILE_SIZE], *p1 = rbuf, *p2 = rbuf, wbuf[FILE_SIZE], *p3 = wbuf;
#ifdef LOCAL
inline char getc() {return getchar();}
inline void putc(char c) {putchar(c);}
#else
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
#endif
template<typename T> void read(T &x) {
	x = 0; char c = getc(); T neg = 0;
	while (!isdigit(c)) neg |= (c == '-'), c = getc();
	while (isdigit(c)) x = x * 10 + (c - '0'), c = getc();
	if (neg) x = -x;
}
template<typename T> void recursive_print(T x) {
	if (!x) return;
	recursive_print(x / 10); putc(x % 10 ^ 48);
}
template<typename T> void print(T x) {
	if (!x) putc('0'); if (x < 0) putc('-'), x = -x;
	recursive_print(x);
}
template<typename T> void print(T x, char c) {print(x); putc(c);}
void readstr(char *s) {
	char c = getc();
	while (c <= 32 || c >= 127) c = getc();
	while (c > 32 && c < 127) s[0] = c, s++, c = getc();
	(*s) = 0;
}
void printstr(string s) {for (int i = 0; i < s.size(); i++) putc(s[i]);}
void printstr(char *s) {
	int len = strlen(s);
	for (int i = 0; i < len; i++) putc(s[i]);
}
void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
#endif
const int MAXN = 5000;
int n, mod, fac[MAXN + 5], ifac[MAXN + 5], res;
void init_fac(int n) {
	for (int i = (fac[0] = ifac[0] = ifac[1] = 1) + 1; i <= n; i++)
		ifac[i] = 1ll * ifac[mod % i] * (mod - mod / i) % mod;
	for (int i = 1; i <= n; i++) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		ifac[i] = 1ll * ifac[i - 1] * ifac[i] % mod;
	}
}
int dp[MAXN + 5][MAXN + 5], sdp[MAXN + 5][MAXN + 5], pw[MAXN + 5][MAXN + 5];
int main() {
#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#endif
	scanf("%d%d", &n, &mod); init_fac(MAXN);
	for (int i = 0; i <= n; i++) for (int j = (pw[i][0] = 1); j <= n; j++)
		pw[i][j] = 1ll * pw[i][j - 1] * i % mod;
	dp[0][0] = 1; for (int i = 0; i <= n; i++) sdp[0][i] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 2; j <= n; j++) dp[i][j] = sdp[i - 1][j - 2];
		for (int j = 1; j <= n; j++) sdp[i][j] = (sdp[i][j - 1] + dp[i][j]) % mod;
	}
	for (int i = 0; i <= n; i++) for (int j = 1; j <= n - i; j++) {
		int V = 1ll * dp[j][n - i] % mod * ifac[i] % mod * ifac[j] % mod * fac[n] % mod;
		res = (res + 1ll * pw[n - 1][j] * pw[n - i - j][i] % mod * V) % mod;
	}
	printf("%d\n", res);
	return 0;
}