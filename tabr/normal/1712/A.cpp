#include <bits/stdc++.h>
using namespace std;
#ifdef tabr
#include "library/debug.cpp"
#else
#define debug(...)
#endif

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int tt;
    cin >> tt;
    while (tt--) {
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        for (int i = 0; i < n; i++) {
            cin >> p[i];
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            if (p[i] > k) {
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}