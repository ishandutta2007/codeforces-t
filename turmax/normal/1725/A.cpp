#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int n,m;cin>>n>>m;
    if(m==1) {cout<<(n-1);} else {cout<<(m-1)*n;}
    return 0;
}