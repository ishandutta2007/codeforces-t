// Created time: 2022/7/2 15:55:58
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
const int MAXN = 1e6;
char s[MAXN + 5], t[MAXN + 5];
int n, m, id[128], nxt[MAXN + 5][3], sum[MAXN + 5][3][3];
int main() {
	scanf("%s%s", s + 1, t + 1); id['R'] = 0; id['G'] = 1; id['B'] = 2;
	n = strlen(s + 1); m = strlen(t + 1);
	for (int i = 0; i < 3; i++) nxt[m + 1][i] = m;
	for (int i = m; i; i--) {
		for (int j = 0; j < 3; j++) nxt[i][j] = nxt[i + 1][j];
		nxt[i][id[t[i]]] = i;
	}
	for (int i = 2; i <= m; i++) if (t[i - 1] != t[i]) sum[i][id[t[i - 1]]][id[t[i]]] = 1;
	for (int i = 1; i <= m; i++) for (int j = 0; j < 3; j++) for (int k = 0; k < 3; k++)
		sum[i][j][k] += sum[i - 1][j][k];
	int l = 1, r = nxt[1][id[s[1]]]; ll res = r - l + 1;
	for (int i = 1; i < n; i++) {
		l = (s[i] != t[l]) ? l : (l + 1);
		r = (s[i] != t[r]) ? r : (r + 1);
		r = nxt[r][id[s[i + 1]]];
		if (l > r) break; res += r - l + 1;
		if (s[i] != s[i + 1]) res -= sum[r][id[s[i + 1]]][id[s[i]]] - sum[l - 1][id[s[i + 1]]][id[s[i]]];
	}
	printf("%lld\n", res);
	return 0;
}