#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(x) x.begin(), x.end()
#define sumvt(x) accumulate(all(x), 0ll)
#define sumat(v, n) accumulate(v, v+n, 0ll)
#define vt vector
#define ar array
template<class t>
void read(t a) {
	cin >> a;
}
template<class t>
void read(vt<t> &a) {
	for(auto &b: a)
		cin >> b;
}
template<class t>
void read(vt<pair<t,t>> &a) {
	for(auto &b: a)
		cin >> b.first >> b.second;
}
template<class t>
void read(vt<ar<t,2>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1];
}
template<class t>
void read(vt<ar<t,3>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2];
}
template<class t>
void read(vt<ar<t,4>> &a) {
	for(auto &b: a)
		cin >> b[0] >> b[1] >> b[2] >> b[3];
}

template<class t> void print(t &a) {
	cout << a << "\n";
}
template<class T> void print(vt<T> &a) {
	for(auto &e: a)
		cout << e << " ";
	cout << "\n";
}
template<class T, class V> void print(vt<pair<T, V>> &a) {
	for(auto &e: a)
		cout << e.first << " " << e.second << "\n";
}
template<class T, int SZ_> void print(vt<ar<T, SZ_>> &a) {
	for(auto &e: a) {
		for(auto &b: e) cout << b << " ";
		cout << "\n";
	}
}
#define sz(x) (int(x.size()))
void solve() {
	ll n; cin >> n;
	vt<int> a(n);
	read(a);
	vt<int> dp(n);
	dp[n-1] = 0;

	for(int i = n-1; ~i; i--) {
		int choice = a[i];
		dp[i] += choice;
		if(i + choice < n) {
			dp[i] += dp[i + choice];
		}
	}

	cout << *max_element(dp.begin(), dp.end()) << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0);

	int t; cin >> t;

	while(t--) {
		solve();

	}
}