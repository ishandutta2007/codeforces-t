#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <cassert>

std::mt19937 rng((int) std::chrono::steady_clock::now().time_since_epoch().count());

int main() {
	std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
	int n;
	std::cin >> n;
	std::string str;
	std::cin >> str;
	std::vector<int> f(26, 0);
	int ans = 0;
	for(int i = 0; i < (int) str.size(); i++) {
		if(i % 2 == 0) {
			int x = str[i] - 'a';
			f[x]++;
		} else {
			int x = str[i] - 'A';
			if(f[x]) {
				f[x]--;
			} else {
				ans++;
			}
		}
	}
	std::cout << ans << '\n';
}