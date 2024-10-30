/*
    ___                         ______      __                  __
   /   |____  __  ___________ _/ ____/___ _/ /___  ____  ______/ /____
  / /| /_  / / / / / ___/ __ `/ /   / __ `/ __/ / / / / / / __  / ___/
 / ___ |/ /_/ /_/ (__  ) /_/ / /___/ /_/ / /_/ /_/ / /_/ / /_/ (__  )
/_/  |_/___/\__,_/____/\__,_/\____/\__,_/\__/\__, /\__, /\__,_/____/
                                            /____//____/

 
| _ _|
 ` _x 
  /  |
 /   ?
| |||
| (__)_)


*/

#include <queue>
#include <vector>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define MP make_pair
#define ll long long
#define fi first
#define se second
using namespace std;

template <typename T>
void read(T &x) {
    x = 0; bool f = 0;
    char c = getchar();
    for (;!isdigit(c);c=getchar()) if (c=='-') f=1;
    for (;isdigit(c);c=getchar()) x=x*10+(c^48);
    if (f) x=-x;
}

template<typename F>
inline void write(F x, char ed = '\n') {
	static short st[30];short tp=0;
	if(x<0) putchar('-'),x=-x;
	do st[++tp]=x%10,x/=10; while(x);
	while(tp) putchar('0'|st[tp--]);
	putchar(ed);
}

template <typename T>
inline void Mx(T &x, T y) { x < y && (x = y); }

template <typename T>
inline void Mn(T &x, T y) { x > y && (x = y); }

const int N = 200500;
int a[N], cnt[5], T, x, y, n;
char s[N];
int main() {
	for (read(T); T; T--) {
		read(x), read(y);
		scanf ("%s", s + 1), n = strlen(s + 1);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 1;i <= n; ++i) {
			if (s[i] == 'L') cnt[0]++;
			if (s[i] == 'R') cnt[1]++;
			if (s[i] == 'U') cnt[3]++;
			if (s[i] == 'D') cnt[2]++;
		}
		int fl = 1;
		if (x < 0) fl &= cnt[0] >= -x;
		else fl &= cnt[1] >= x;
		if (y < 0) fl &= cnt[2] >= -y;
		else fl &= cnt[3] >= y;
		puts(fl ? "YES" : "NO");
	}
	return 0;
}