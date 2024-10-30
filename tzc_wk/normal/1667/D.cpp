// Created time: 2022/4/22 14:29:05
#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/hash_policy.hpp>
// #include <ext/pb_ds/priority_queue.hpp>
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
inline char getc() {return p1 == p2 && (p2 = (p1 = rbuf) + fread(rbuf, 1, FILE_SIZE, stdin), p1 == p2) ? -1 : *p1++;}
inline void putc(char x) {*p3++ = x;}
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
const int MAXN = 2e5;
int n, hd[MAXN + 5], to[MAXN * 2 + 5], nxt[MAXN * 2 + 5], ec = 0;
void adde(int u, int v) {to[++ec] = v; nxt[ec] = hd[u]; hd[u] = ec;}
int st[MAXN + 5]; bool flg = 0;
void dfs1(int x, int f) {
	int cnt[2] = {0, 0};
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e]; if (y == f) continue;
		dfs1(y, x); cnt[st[y]]++;
	}
	if (x != 1) {
		st[x] = (cnt[0] >= cnt[1]);
		cnt[st[x]]++;
	}
	if (cnt[1] < cnt[0] || cnt[1] - cnt[0] > 1) flg = 1;
}
void dfs2(int x, int f) {
	vector<int> vec[2];
	for (int e = hd[x]; e; e = nxt[e]) {
		int y = to[e];
		if (y == f) vec[st[x]].pb(x);
		else vec[st[y]].pb(y);
	}
	int cur = vec[0].size() + vec[1].size(), id = cur & 1;
	for (int i = 0; i < cur; i++) {
		int pt = vec[id].back(); vec[id].ppb();
		if (pt == x) printf("%d %d\n", x, f);
		else dfs2(pt, x);
		id ^= 1;
	}
}
void solve() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) hd[i] = 0; ec = flg = 0;
	for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), adde(u, v), adde(v, u);
	dfs1(1, 0);
	if (flg) puts("NO");
	else {puts("YES"); dfs2(1, 0);}
}
int main() {
	int qu; scanf("%d", &qu);
	while (qu--) solve();	
	return 0;
}