#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>
#include <algorithm>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int n;
		std::cin >> n;
		std::vector<std::pair<int, int>> a(n);
		for(int i = 0; i < n; i++) {
			std::cin >> a[i].first;
			a[i].second = i;
		}
		std::sort(a.begin(), a.end());
		std::cout << (a[0].first == a[1].first ? a.back().second + 1 : a[0].second + 1) << '\n';
	}
}