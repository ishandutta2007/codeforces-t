#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <cstring>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#pragma comment(linker, "/STACK:167772160")
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-8;
const int MAXN = 1e4 + 10;

int h;
long long n, ans(0);
bool cmd(0);

void init()
{
    cin >> h >> n;
    --n;
}

void solve()
{
    if(n & (1LL << (h - 1)))
        ans = 1LL << h;
    else
        ans = 1;
    for(long long i(h - 2); i >= 0; --i)
    if((n & (1LL << i)) && (n & (1LL << (i + 1))) ||
        !(n & (1LL << i)) && !(n & (1LL << (i + 1))))
        ans += 1LL << (i + 1);
    else
        ++ans;
}

void output()
{
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    init();
    solve();
    output();
    return 0;
}