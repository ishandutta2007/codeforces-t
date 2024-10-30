#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) (x).size())
typedef long long ll;
typedef pair<int,int> pii;
template<class T> void print(T & x){ cout << x; }
template<class T,class U> void print(pair<T,U> & p){cout << "("; print(p.first); cout << ", "; print(p.second); cout << ")"; }
template<class T> void print(vector<T> & v) {
  cout << "{";
  if (sz(v)) print(v[0]);
  for (int i = 1; i < sz(v); i++) cout << ", ", print(v[i]);
  cout << "}\n";
}

const int INF = 1e7;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while(T--){
    int N;
    cin >> N;
    vector<int> A(N+2);
    vector<int> a(N+2), b(N+2);
    for(int i=2; i<=N+1; i++)
      cin >> A[i];
    a[0] = a[1] = INF;
    for(int i=2; i<=N+1; i++){
      a[i] = min(b[i-1]+A[i], b[i-2]+A[i]+A[i-1]);
      b[i] = min(a[i-1], a[i-2]);
    }
    cout << min(a[N+1], b[N+1]) << "\n";
  }
}