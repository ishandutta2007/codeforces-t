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
        int n;
        cin >> n;
        vector<int> a(2 * n + 10);
        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            if (a[x]) {
                a[x + 1] = 1;
            } else {
                a[x] = 1;
            }
        }
        cout << accumulate(a.begin(), a.end(), 0) << '\n';
    }
    return 0;
}