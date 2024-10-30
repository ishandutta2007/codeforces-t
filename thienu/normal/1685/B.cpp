#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

void solve(){
    int a, b, ab, ba;
    cin >> a >> b >> ab >> ba;
    string s;
    cin >> s;
    int n = s.size();
    int acnt = 0;
    for(int i = 0; i < n; i++){
        acnt += s[i] == 'A';
    }
    if(acnt != a + ab + ba){
        cout << "NO" << endl;
        return;
    }

    int abcnt = 0, bacnt = 0;
    int shared = 0;
    vi abg, bag;
    char sc;
    int len = -1;
    for(int i = 1; i < n; i++){
        if(s[i] == s[i-1] && len != -1){
            if(len & 1){
                shared += len / 2;
            }else{
                if(sc == 'A'){
                    abg.push_back(len / 2);
                    abcnt += len / 2;
                }else if(sc == 'B'){
                    bag.push_back(len / 2);
                    bacnt += len / 2;
                }
            }
            len = -1;
        }
        if(s[i] != s[i-1]){
            if(len == -1){
                len = 2;
                sc = s[i-1];
            }else{
                len++;
            }
        }
    }
    if(len != -1){
        if(len & 1){
            shared += len / 2;
        }else{
            if(sc == 'A'){
                abg.push_back(len / 2);
                abcnt += len / 2;
            }else if(sc == 'B'){
                bag.push_back(len / 2);
                bacnt += len / 2;
            }
        }
        len = -1;
    }
    debug(shared, bag, abg, abcnt, bacnt);

    if(abcnt < ab){
        int delta = min(shared, ab - abcnt);
        shared -= delta;
        abcnt += delta;
    }

    if(bacnt < ba){
        int delta = min(shared, ba - bacnt);
        shared -= delta;
        bacnt += delta;
    }
    
    if(abcnt >= ab && bacnt >= ba){
        cout << "YES" << endl;
        return;
    }

    if(abcnt < ab && bacnt < ba){
        cout << "NO" << endl;
        return;
    }

    if(abcnt < ab){
        swap(ab, ba);
        swap(abcnt, bacnt);
        swap(abg, bag);
    }

    // abcnt >= ab and bacnt < ba

    debug(bag, abg, abcnt, bacnt);

    sort(abg.begin(), abg.end());

    reverse(abg.begin(), abg.end());

    for(int i : abg){
        int removed = min(abcnt - ab, i);
        if(removed == 0){
            cout << "NO" << endl;
            return;
        }
        abcnt -= removed;
        bacnt += removed - 1;
        if(bacnt >= ba){
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc;
    cin >> tc;
    while(tc--){
        solve();
    }
    return 0;
}