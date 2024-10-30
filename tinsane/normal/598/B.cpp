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
#include <bitset>
#include <unordered_map>

#pragma comment(linker, "/STACK:167772160")

using namespace std;

#define mk make_pair

typedef pair<int, int> pii;

//8739

const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-9;
const int MAXN = 2e3 + 10;

string s, tmp;
int n, m, l, r, k;

void init()
{
    cin >> s >> m;
    n = s.size();
}

void solve()
{
    while(m--)
    {
        cin >> l >> r >> k;
        --l, --r;
        tmp = "";
        k %= (r - l + 1);
        for(int i(r + 1 - k); i <= r; ++i)
            tmp += s[i];
        for(int i(l); i < r + 1 - k; ++i)
            tmp += s[i];
        for(int i(0); i < r - l + 1; ++i)
            s[i + l] = tmp[i];
    }
}

void output()
{
    cout << s;
}

int main()
{
    ios_base::sync_with_stdio(0), cin.tie(0);
    init();
    solve();
    output();
    return 0;
}