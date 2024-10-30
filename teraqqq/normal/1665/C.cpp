#include <bits/stdc++.h>

#define F first
#define S second

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

using namespace std;
using pi = pair<int, int>;
using vi = vector<int>;
using ll = long long;

template<class T> bool ckmin(T&a, const T& b) { return b < a ? a = b, true : false; }
template<class T> bool ckmax(T&a, const T& b) { return a < b ? a = b, true : false; }

template<class T> using pq_max = priority_queue<T, vector<T>, less<T>>;
template<class T> using pq_min = priority_queue<T, vector<T>, greater<T>>;

const int INF = 1e9+7;

void solve() {
    int n; cin >> n;
    vector<int> cnt(n);
    for (int i = 1; i < n; ++i) {
        int p; cin >> p; --p;
        cnt[p]++;
    }

    cnt.push_back(1);

    sort(rall(cnt));
    while (cnt.back() == 0) cnt.pop_back();

    const int k = cnt.size();
    int ans = k;

    pq_max<int> q;
    for (int i = 0; i < k; ++i) q.push(cnt[i] + i);

    while (ans + 1 < q.top()) {
        ans++;
        q.push(q.top() - 1);
        q.pop();
    }

    cout << max(ans, q.top()) << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    int t = 1;
    cin >> t;
    while (t--) solve();
}