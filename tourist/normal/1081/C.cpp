/**
 *    author:  tourist
 *    created: 16.12.2018 17:37:50       
**/
#include <bits/stdc++.h>

using namespace std;

const int md = 998244353;

inline void add(int &a, int b) {
  a += b;
  if (a >= md) a -= md;
}

inline void sub(int &a, int b) {
  a -= b;
  if (a < 0) a += md;
}

inline int mul(int a, int b) {
  return (int) ((long long) a * b % md);
}

inline int power(int a, long long b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

inline int inv(int a) {
  a %= md;
  if (a < 0) a += md;
  int b = md, u = 0, v = 1;
  while (a) {
    int t = b / a;
    b -= t * a; swap(a, b);
    u -= t * v; swap(u, v);
  }
  assert(b == 1);
  if (u < 0) u += md;
  return u;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  k = n - 1 - k;
  int ans = m;
  for (int i = 2; i <= n - k; i++) {
    ans = mul(ans, m - 1);
  }
  for (int i = 1; i <= n - 1; i++) {
    ans = mul(ans, i);
  }
  for (int i = 1; i <= k; i++) {
    ans = mul(ans, inv(i));
  }
  for (int i = 1; i <= n - 1 - k; i++) {
    ans = mul(ans, inv(i));
  }
  cout << ans << '\n';
  return 0;
}