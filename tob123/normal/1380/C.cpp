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


int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int N, T;
  ll X;
  cin >> T;
  while(T--){
    cin >> N >> X;
    vector<int> A(N);
    for(int i=0; i<N; i++){
      cin >> A[i];
    }
    sort(A.begin(), A.end());
    int cnt = 0;
    int res = 0;
    for(int i=N-1; i>=0; i--){
      cnt++;
      if(A[i]*cnt >= X){
        res++;
        cnt = 0;
      }
    }
    cout << res << "\n";
  }
}