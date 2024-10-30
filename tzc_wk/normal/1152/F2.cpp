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
#ifdef FASTIO
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
using namespace fastio;
#endif
const int MAXK = 12;
const int MAXP = 16;
const int MAXC = 215;
const int MOD = 1e9 + 7;
int n, k, m, id[MAXK + 3][MAXP + 3], idcnt = 0;
struct mat {
	int a[MAXC + 5][MAXC + 5];
	mat() {memset(a, 0, sizeof(a));}
	mat operator * (const mat &rhs) {
		mat ret;
		for (int i = 1; i <= idcnt; i++) for (int j = 1; j <= idcnt; j++) for (int t = 1; t <= idcnt; t++)
			ret.a[i][j] = (ret.a[i][j] + 1ll * a[i][t] * rhs.a[t][j]) % MOD;
		return ret;
	}
} trs, pw;
int main() {
	scanf("%d%d%d", &n, &k, &m);
	for (int j = 0; j <= k; j++) for (int S = 0; S < (1 << m); S++) id[j][S] = ++idcnt;
	for (int j = 0; j <= k; j++) for (int S = 0; S < (1 << m); S++) {
		if ((S << 1) < (1 << m)) {
			trs.a[id[j][S]][id[j][S << 1]]++;
			if (j + 1 <= k) {
				trs.a[id[j][S]][id[j + 1][S << 1]] += __builtin_popcount(S) + 1;
				trs.a[id[j][S]][id[j + 1][S << 1 | 1]] += __builtin_popcount(S) + 1;
			}
		}
		if (j + 1 <= k) {
			for (int l = 0; l < m; l++) if (S >> l & 1) {
				int nmsk = (S ^ (1 << l)) << 1;
				if (nmsk < (1 << m)) {
					trs.a[id[j][S]][id[j + 1][nmsk]]++;
					trs.a[id[j][S]][id[j + 1][nmsk | 1]]++;
				}
			}
		}
	}
	for (int i = 1; i <= idcnt; i++) pw.a[i][i] = 1;
	for (; n; n >>= 1, trs = trs * trs) if (n & 1) pw = pw * trs;
	printf("%d\n", pw.a[id[0][0]][id[k][0]]);
	return 0;
}