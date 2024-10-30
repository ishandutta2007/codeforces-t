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
		if (x<0) putc('-'), x = -x;
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
	void print_final() {fwrite(wbuf, 1, p3-wbuf, stdout);}
}
const int MAXN = 2e5;
const int INF = 0x3f3f3f3f;
const ll INFll = 0x3f3f3f3f3f3f3f3fll;
int n; ll a[MAXN + 5];
int Rand() {return ((rand() & 32767) << 15) | (rand() & 32767);}
ll getsum(ll p) {
	ll sum = 0;
	for (int i = 1; i <= n; i++) {
		ll lim = a[i] / p * p;
		sum += min((!lim) ? INFll : (a[i] - lim), lim + p - a[i]);
	}
	return sum;
}
int calc(ll x) {
	int res = INF;
	if (!x) return INF;
	for (int i = 2; 1ll * i * i <= x; i++) if (x % i == 0) {
		chkmin(res, getsum(i));
		while (x % i == 0) x /= i;
	}
	if (x > 1) chkmin(res, getsum(x));
	return res;
}
int main() {
	scanf("%d", &n); srand(20211204113036);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	int T = 20, res = INF;
	while (T--) {
		int x = Rand() % n + 1;
		chkmin(res, calc(a[x]));
		chkmin(res, calc(a[x] + 1));
		chkmin(res, calc(a[x] - 1));
	}
	printf("%d\n", res);
	return 0;
}