#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;cin>>t;
    while(t--)
    {
        int n;cin>>n;int a[n];for(int i=0;i<n;++i) cin>>a[i];
        sort(a,a+n);cout<<a[n-1]+a[n-2]<<'\n';
    }
    return 0;
}