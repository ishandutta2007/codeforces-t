#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define F first
#define S second
#define append push_back
#define forn(i, n) for(int i = 0; i < n; ++i)
#define forl(i, n) for(long long i=0;i<n;++i)
typedef double dd;
typedef long long ll;
ll exp(ll n, ll m, ll md){
    ll a = 1;
    while (m > 0){
        if (m&1) a = (a * n%md) % md;
        m /= 2;
        n = (n*n) % md;
    }
    return a % md;
}
void printvector(vector<ll>&v)
{
	for(int i=0;i<v.size();i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<"\n";
}
int main()
{
	fast;
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> v(n);
		set<int> s;
		for(int i=0;i<n;i++)
		{
			cin>>v[i];
			s.insert(v[i]);
		}
		if(s.size()>k) cout<<-1<<"\n";
		else
		{
			cout<<n*k<<"\n";
			for(int i=0;i<n;i++)
			{
				for(auto j:s)
				{
					cout<<j<<" ";
				}
				for(int j=0;j<k-s.size();j++)
				{
					cout<<1<<" ";
				}
			}
			cout<<"\n";
		}
	}
}