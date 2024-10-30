#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <limits>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int t;
	std::cin >> t;
	while(t--) {
		long long a, b, n;
		std::cin >> a >> b >> n;
		std::cout << a * ((n + 1) / 2) - b * (n / 2) << '\n';
	}
}