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

/*
#pragma GCC optimize ("O3")
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2,fma")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC target ("avx2")
#pragma GCC optimization ("unroll-loops")
#pragma comment(linker, "/STACK: 20000000005")
*/

using namespace std;

const int N = 200005, MOD = 1e9 + 7;

int mas[N];


main()
{
    //freopen ("in.in", "r", stdin);freopen ("out.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    if (n % 2 == 0){
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;
    int x = 0, y = 1;
    int a = 1, b = 2;
    for (int i = 1; i <= n; i++){
        mas[i + x * n] = a;
        mas[i + y * n] = b;
        a += 2;
        b += 2;
        swap (x, y);
    }
    for (int i = 1; i <= n * 2; i++)
        cout << mas[i] << " ";
    cout << endl;
    return 0;
}