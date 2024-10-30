#include <bits/stdc++.h>
#define F first
#define S second
#define mp make_pair
#define pb push_back
//#define ll __int128
#define ll long long
#define LEFT(a) ((a)<<1)
#define RIGHT(a) (LEFT(a) + 1)
#define MID(a,b) ((a+b)>>1)
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define y1 y122

#pragma GCC optimize ("O3")
/*
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

int n;
int a[2005];
int b[2005];

int ans;
vector < int > A, B;

main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++){
        int x;
        cin >> x;
        b[x] = i;
    }
    for (int i = 1; i <= n; i++){
        a[i] = b[a[i]];
        ans += abs (a[i] - i);
    }
    ans >>= 1;
    cout << ans << endl;
    for (int i = n; i >= 1; i--){
        if (a[i] == i)
            continue;
        int x = 0;
        for (int j = 1; j <= i; j++)
            if (a[j] == i)
                x = j;
        for (int j = x + 1; j <= i; j++){
            if (a[j] <= x){
                A.pb (x);
                B.pb (j);
                swap (a[x], a[j]);
                x = j;
            }
        }
    }
    cout << A.size() << endl;
    for (int i = 0; i < A.size(); i++)
        printf ("%d %d\n", A[i], B[i]);
}