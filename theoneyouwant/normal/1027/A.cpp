/*
Copyright SHUBHAM ANAND JAIN, IIT BOMBAY
I JUST DID THIS CAUSE IT WAS FUN :P 
*/

#include<bits/stdc++.h>
#include <iomanip>

using namespace std;

#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
typedef vector<int> VI;
typedef long long ll;
typedef pair<int,int> PII;
const int mod = 1e9 + 7;
const long double epsilon = 1e-9;
typedef pair<int, int> ii; 
typedef vector<ii> vii;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
   	for(int i=0;i<n;i++)
   	{
   		int b,c;
   		cin>>b;
   		b=0;
   		string s;
   		cin>>s;
   		for(int i=0;i<s.length();i++)
   		{
   			c=s[i];
   			if(c==s[s.length()-i-1] || abs(c-s[s.length()-i-1])==2)
   			{

   			}
   			else
   			{
   				b=1;
   			}
   		}
   		if(b==1)
   		{
   			cout<<"NO"<<endl;
   		}
   		else
   		{
   			cout<<"YES"<<endl;
   		}
   	}
    
     return 0;
}