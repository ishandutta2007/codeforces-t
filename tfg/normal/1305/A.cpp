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
		for(int rep = 0; rep < 2; rep++) {
			std::vector<int> a(n);
			for(int i = 0; i < n; i++) {
				std::cin >> a[i];
			}
			std::sort(a.begin(), a.end());
			for(int i = 0; i < n; i++) {
				std::cout << a[i] << (i + 1 == n ? '\n' : ' ');
			}
		}
	}
}