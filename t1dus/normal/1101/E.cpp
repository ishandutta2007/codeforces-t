#include<bits/stdc++.h>
using namespace std;

#define ll long long
// #define int ll
#define pb push_back
#define INF 1000000000
#define MOD 1000000007
#define mp make_pair
const double PI=3.141592653589793238462643383279502884197169399375105820974944;
#define REP(i,n) for (int i = 0; i < n; i++)
#define FOR(i,a,b) for (int i = a; i < b; i++)
#define REPD(i,n) for (int i = n-1; i >= 0; i--)
#define FORD(i,a,b) for (int i = a; i >= b; i--)
#define remax(a,b) a = max(a,b)
#define remin(a,b) a = min(a,b)
#define all(v) v.begin(),v.end()
#define pii pair<int,int>
#define F first
#define S second
#define mii map<int,int>
#define vi vector<int>
#define vvi vector<vi>
#define itr :: iterator it
#define WL(t) while(t --)
#define gcd(a,b) __gcd((a),(b))
#define lcm(a,b) ((a)*(b))/gcd((a),(b))
#define print(arr) for (auto it = arr.begin(); it != arr.end(); ++it) cout << *it << " "; cout << endl;
#define debug(x) cout << x << endl;
#define debug2(x,y) cout << x << " " << y << endl;
#define debug3(x,y,z) cout << x << " " << y << " " << z << endl;

signed main(){
  ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
  
  int n; cin >> n;//scanf("%d",&n);
  int x = 0,y = 0;
  REP(i,n){
    char c;
    int m,n;
    // scanf("%c%d%d\n",&c,&m,&n);
    cin >> c >> m >> n;
    // cout << c << " " << m << " " << n << endl;
    if(m > n) swap(m,n);
    if(c == '+'){
      remax(x,m);
      remax(y,n);
    }
    else{
      if (m >= x and n >= y){
        // printf("YES\n");
        cout << "YES" << endl;
      }
      else{
        cout << "NO" << endl;
      }
    }
  }
}