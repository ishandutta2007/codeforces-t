#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int b, p, f, h, c;
		cin >> b >> p >> f >> h >> c;
		int ans = 0;
		for (int i = 0; 2 * i <= b; ++i) {
			for (int j = 0; 2 * i + 2 * j <= b; ++j) {
				if (i <= p && j <= f) {
					ans = max(ans, i * h + j * c);
				}
			}
		}
		cout << ans << '\n';
	}
}