#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/trie_policy.hpp>
// #include <ext/rope>

using namespace std;
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

void Hollwo_Pelw();

signed main(){
#ifndef hollwo_pelw_local
	if (fopen(".inp", "r"))
		assert(freopen(".inp", "r", stdin)), assert(freopen(".out", "w", stdout));
#else
	using namespace chrono;
	auto start = steady_clock::now();
#endif
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);
	int testcases = 1;
	// cin >> testcases;
	for (int test = 1; test <= testcases; test++){
		// cout << "Case #" << test << ": ";
		Hollwo_Pelw();
	}
#ifdef hollwo_pelw_local
	auto end = steady_clock::now();
	cout << "\nExecution time : " << duration_cast<milliseconds> (end - start).count() << "[ms]" << endl;
#endif
}

#define int long long

const int N = 1e5 + 5;

int n, a[N], bit[N], res;

inline void get(int p) {
	for (; p > 0; p -= p & -p)
		res += bit[p];
}

inline void upd(int p) {
	for (; p < N; p += p & -p)
		bit[p] ++;
}

void Hollwo_Pelw(){
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> a[i], a[i] += a[i - 1];
	vector<int> v(a + 1, a + n + 1);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	if (a[n] == v.back() && v[0] >= 0) {
		for (int i = n; i; i--) {
			int p = upper_bound(v.begin(), v.end(), a[i]) - v.begin(); get(p - 1), upd(p);
		}
		cout << res << '\n';
	} else {
		cout << "-1\n";
	}
}