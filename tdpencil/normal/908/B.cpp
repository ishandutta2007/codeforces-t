#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

typedef long long ll;
typedef long double ld;
#define pb push_back
#define all(x) x.begin(),x.end()
#define uid(a, b) uniform_int_distribution<int>(a, b)(rng)
#define f first
#define s second
#define ar array
#define vt vector
#define ub upper_bound
#define lb lower_bound
#define V vector
#define nl '\n'
#define vi vector<int>
#define pii pair<int, int>
#define pi pair<int, int>
#define pl pair<ll, ll>
#define vt vector
#define vl vector<ll>
#define vpi vector<pi>
#define vpl vt<pl>
#define trav(x,y) for(auto &x:y)
#define vb vector<bool>
#define ull unsigned long long
#define sz(x) int(x.size())
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define F0R(i,N) rep(i,0,N)
#define P pair


const int mxN=1e5,M=998244353,mod=1e9+7;
const ll MOD = 1e9+7;
template<typename K> using pq = priority_queue<K>;
template<typename K> using pqg = priority_queue<K, vt<K>, greater<K>>;
template<typename K> using dq = deque<K>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)













































// right, down, left, up
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
// 1, 3, 2, 0
string instructions;


void solve(int test_case = 0) {
	int N, M;
	cin >> N >> M;
	vector<string> G(N);
	for(auto &e: G)
		cin >> e;
	pii robot, finish;
	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if(G[i][j] == 'S') robot = {i, j};
			if(G[i][j] == 'E') finish = {i, j};
		}
	}
	// dbg(robot);
	// dbg(finish);
	
	cin >> instructions;
	auto move = [&](pii &robot, int pos) -> bool {
		robot.f += dx[pos];
		robot.s += dy[pos];
		if(robot.f < 0 || robot.f >= N)
			return false;
		else if(robot.s < 0 || robot.s >= M)
			return false;
		else if(G[robot.f][robot.s] == '#')
			return false;
		return true;
	};
	vi directions(4);
	iota(directions.begin(), directions.end(), 0);
	
	int ans = 0;
	do {
		pii robo = robot;
		bool works = true;
		for(char ch : instructions) {
			if(!move(robo, directions[ch - '0']))
				works = false;
			else if(robo == finish && works) {
				++ans;
				break;
			}
		}
		
	} while(next_permutation(begin(directions), end(directions)));

	cout << ans << nl;
}



int main()
{
    //setup();
    cin.tie(0)->sync_with_stdio(0);
    //precalc();
    int T = 1;
    // cin >> T;
    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}