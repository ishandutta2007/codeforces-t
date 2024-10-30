#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/hash_policy.hpp>
using namespace std;
//using namespace __gnu_pbds;
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
		x = 0; char c = getc(); T neg = 0;
		while (!isdigit(c)) neg |= !(c ^ '-'), c = getc();
		while (isdigit(c)) x = (x << 3) + (x << 1) + (c ^ 48), c = getc();
		if (neg) x = (~x) + 1;
	}
	template <typename T> void recursive_print(T x) {
		if (!x) return;
		recursive_print (x / 10);
		putc (x % 10 ^ 48);
	}
	template <typename T> void print(T x) {
		if (!x) putc('0');
		if (x < 0) putc('-'), x = -x;
		recursive_print(x);
	}
	template <typename T> void print(T x,char c) {print(x); putc(c);}
	void readstr(char *s) {
		char c = getc();
		while (c <= 32 || c >= 127) c = getc();
		while (c > 32 && c < 127) s[0] = c, s++, c = getc();
		(*s) = 0;
	}
	void printstr(string s) {
		for (int i = 0; i < s.size(); i++) putc(s[i]);
	}
	void printstr(char *s) {
		int len = strlen(s);
		for (int i = 0; i < len; i++) putc(s[i]);
	}
	void print_final() {fwrite(wbuf, 1, p3 - wbuf, stdout);}
}
const int MAXN = 1e5;
const int MAXV = 3e5;
const int MOD = 998244353;
int qpow(int x, int e) {
	int ret = 1;
	for (; e; e >>= 1, x = 1ll * x * x % MOD)
		if (e & 1) ret = 1ll * ret * x % MOD;
	return ret;
}
int n, a[MAXN + 5], sum = 0;
struct line {
	int k, b;
	line() {k = b = 0;}
	line(int _k, int _b): k(_k), b(_b) {}
	line operator + (const line &rhs) {return line((k + rhs.k) % MOD, (b + rhs.b) % MOD);}
	line operator - (const line &rhs) {return line((k - rhs.k + MOD) % MOD, (b - rhs.b + MOD) % MOD);}
	line operator * (const int &rhs) {return line(1ll * k * rhs % MOD, 1ll * b * rhs % MOD);}
	line operator + (const int &rhs) {return line(k, (b + rhs) % MOD);}
	line operator / (const int &rhs) {int iv = qpow(rhs, MOD - 2); return line(1ll * k * iv % MOD, 1ll * b * iv % MOD);}
} dp[MAXV + 5];
int dpv[MAXV + 5];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), sum += a[i];
	dp[0] = line(1, 0);
	for (int i = 0; i < sum; i++) {
		dp[i + 1] = dp[i] - dp[i] * (sum - i) * qpow(sum, MOD - 2) * (n - 2) * qpow(n - 1, MOD - 2) + (MOD - 1);
		if (i) dp[i + 1] = dp[i + 1] - dp[i - 1] * i * qpow(sum, MOD - 2);
		dp[i + 1] = dp[i + 1] * (n - 1) * sum * qpow(sum - i, MOD - 2);
	}
//	for (int i = 0; i <= sum; i++) printf("%d %d\n", dp[i].k, dp[i].b); 
	dpv[0] = 1ll * (MOD - dp[sum].b) * qpow(dp[sum].k, MOD - 2) % MOD;
	for (int i = 1; i <= sum; i++) dpv[i] = (1ll * dpv[0] * dp[i].k + dp[i].b) % MOD;
	int res = 0;
	for (int i = 1; i <= n; i++) res = (res + dpv[a[i]]) % MOD;
	res = (res - 1ll * dpv[0] * (n - 1) % MOD + MOD) % MOD;
	printf("%d\n", 1ll * res * qpow(n, MOD - 2) % MOD);
	return 0;
}