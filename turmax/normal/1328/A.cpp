#include <bits/stdc++.h>

using namespace std;
#define int long long
int32_t main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    while(t--)
    {
    int a,b;
    cin>>a>>b;
    int x=(a%b);
    if(x!=0)
    cout<<(b-x)<<endl;
    else
    cout<<0<<endl;
    }
    return 0;
}