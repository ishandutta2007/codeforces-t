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
  int T, N;
  cin >> T;
  while(T--){
    cin >> N;
    for(int i=0; i<N; i++){
      string s;
      s.push_back('(');
      for(int j=0; j<i; j++){
        s.push_back('(');
      }
      s.push_back(')');
      for(int j=0; j<N-i-1; j++){
        s.push_back('(');
      }
      for(int j=0; j<N-1; j++)
         s.push_back(')');
      cout << s << "\n";
    }
  }
}