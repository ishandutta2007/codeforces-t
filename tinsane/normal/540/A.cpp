#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <queue>
#include <vector>
#include <map>
#include <cmath>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <list>
#include <unordered_map>
using namespace std;
//8739
const double PI = 3.14159265358979323846;
const long long MODUL = 1000000007;
const long long MAXINT = 2e9 + 2;
const long long MAXLL = 2e18 + 2;
const double eps = 1e-11;
const int MAXN = 1e5 + 10;

int main()
{
    ios_base::sync_with_stdio(0);
    int n, res(0);
    string a, b;
    cin >> n >> a >> b;
    for(int i(0); i < n; ++i)
        res += min(abs(a[i] - (int)b[i]), 10 - abs(a[i] - (int)b[i]));
    cout << res;
    return 0;
}