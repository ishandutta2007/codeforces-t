// Created time: 2022/6/12 10:15:54
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
const int MAXN = 1e3;
const int MAXE = 2e6;
const int INF = 0x3f3f3f3f;
int n, m, a[MAXN + 5];
int S, T, hd[MAXN + 5], to[MAXE + 5], nxt[MAXE + 5], cap[MAXE + 5], ec = 1;
void adde(int u, int v, int f) {
	to[++ec] = v; cap[ec] = f; nxt[ec] = hd[u]; hd[u] = ec;
	to[++ec] = u; cap[ec] = 0; nxt[ec] = hd[v]; hd[v] = ec;
}
int dep[MAXN + 5], now[MAXN + 5];
bool getdep(int S, int T) {
	memset(dep, -1, sizeof(dep)); queue<int> q;
	q.push(S); dep[S] = 0;
	while (!q.empty()) {
		int x = q.front(); q.pop(); now[x] = hd[x];
		for (int e = hd[x]; e; e = nxt[e]) {
			int y = to[e], z = cap[e];
			if (z && dep[y] == -1) {
				dep[y] = dep[x] + 1;
				q.push(y);
			}
		}
	}
	return ~dep[T];
}
int getflow(int x, int f) {
	if (x == T) return f; int ret = 0;
	for (int &e = now[x]; e; e = nxt[e]) {
		int y = to[e], z = cap[e];
		if (z && dep[y] == dep[x] + 1) {
			int w = getflow(y, min(f - ret, z));
			cap[e] -= w; cap[e ^ 1] += w; ret += w;
			if (ret == f) return ret;
		}
	}
	return ret;
}
int dinic() {
	int ret = 0;
	while (getdep(S, T)) ret += getflow(S, INF);
	return ret;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		if (2 * a[i] + 1 > m) return puts("-1"), 0;
	}
	T = (S = n + 1) + 1;
	int cnt = 0;
	for (int i = 1; i <= n; i++) if (3ll * a[i] > m) {
		for (int j = 1; j <= n; j++) if (3ll * a[j] <= m && a[i] % a[j] == 0 && 2ll * a[i] + a[j] <= m)
			adde(i, j, 1);
		cnt++;
	}
	for (int i = 1; i <= n; i++) {
		if (3ll * a[i] > m) adde(S, i, 1);
		else adde(i, T, 1);
	}
	if (dinic() != cnt) return puts("-1"), 0;
	vector<pii> res;
	for (int i = 1; i <= n; i++) if (3ll * a[i] > m) {
		for (int e = hd[i]; e; e = nxt[e]) {
			int y = to[e];
			if (to[e] != S && !cap[e]) res.pb(mp(2 * a[i] + a[y], a[i] + a[y]));
		}
	}
	for (int i = 1; i <= n; i++) if (3ll * a[i] <= m) {
		for (int e = hd[i]; e; e = nxt[e]) {
			int y = to[e];
			if (y == T && cap[e]) res.pb(mp(3 * a[i], 2 * a[i]));
		}
	}
	printf("%d\n", (int)(res.size()));
	for (pii p : res) printf("%d %d\n", p.fi, p.se);
	return 0;
}