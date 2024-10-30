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
  int N, M;
  cin >> N >> M;
  vector<int> A(N), B(N);
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
  }
  vector<pii> S(M);
  for(int i=0; i<M; i++){
    cin >> S[i].first >> S[i].second;
  }
  vector<int> U(1000005);
  for(int i=0; i<N; i++){
    for(auto s : S){
      if(s.first >= A[i] && s.second >= B[i]){
        U[s.first-A[i]] = max(U[s.first-A[i]], s.second - B[i] + 1);
      }
    }
  }
  int b = 1e6;
  for(int i=sz(U)-2; i>=0; i--){
    U[i] = max(U[i+1], U[i]);
    b = min(b, i + U[i]);
  }
  cout << b << endl;
}