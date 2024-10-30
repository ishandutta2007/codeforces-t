#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		int sum = 0, mn = 1e9;
		for(int i = 0; i < 3; i++) {
			int x;
			std::cin >> x;
			sum += x;
			mn = std::min(mn, x);
		}
		std::cout << (sum % 9 == 0 && mn >= sum / 9 ? "YES\n" : "NO\n");
	}
}