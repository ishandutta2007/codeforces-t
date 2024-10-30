//teja349
#include <bits/stdc++.h>
// #include <sys/resource.h>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <utility>
#include <algorithm>
#include <cmath>
#include <queue>
#include <stack>
#include <iomanip>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> 
//setbase - cout << setbase (16); cout << 100 << endl; Prints 64
//setfill -   cout << setfill ('x') << setw (5); cout << 77 << endl; prints xxx77
//setprecision - cout << setprecision (14) << f << endl; Prints x.xxxx
//cout.precision(x)  cout<<fixed<<val;  // prints x digits after decimal in val
// g++ -std=c++17 -Wl,-stack_size -Wl,0x10000000 candy.cpp


using namespace std;
using namespace __gnu_pbds;

#define f(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) f(i,0,n)
#define fd(i,a,b) for(i=a;i>=b;i--)
#define pb push_back
#define mp make_pair
#define vi vector< int >
#define vl vector< ll >
#define ss second
#define ff first
#define ll long long
#define pii pair< int,int >
#define pll pair< ll,ll >
#define sz(a) a.size()
#define inf (1000*1000*1000+5)
#define all(a) a.begin(),a.end()
#define tri pair<int,pii>
#define vii vector<pii>
#define vll vector<pll>
#define viii vector<tri>
#define mod (1000*1000*1000+7)
#define pqueue priority_queue< int >
#define pdqueue priority_queue< int,vi ,greater< int > >
#define flush fflush(stdout) 
#define primeDEN 727999983
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

// find_by_order()  // order_of_key
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

#define int ll

int lef, rig;
int inv = 352941179;
int powe[512345];
string s;
int getval(char st){
    if(st=='(')
        return 11;
    else
        return 13;
}
int adder(int st,int cur){
    int len=cur-st+1;
    if(len%2){
        rig-=getval(s[st+len/2])*powe[len/2-1];
        rig%=mod;
    }
    else{
        lef+=getval(s[st+len/2-1])*powe[len/2-1];
    }
    rig*=17;
    rig%=mod;
    rig+=getval(s[cur]);
    lef%=mod;
    rig%=mod;
    if(lef<0)
        lef+=mod;
    if(rig<0)
        rig+=mod;
    return 0;
}

 main(){
    std::ios::sync_with_stdio(false); cin.tie(NULL);
 //    rlimit R;
	// getrlimit(RLIMIT_STACK, &R);
	// R.rlim_cur = R.rlim_max;
	// setrlimit(RLIMIT_STACK, &R);
    int t=1;
    cin>>t;
    int t1=t;
    int i;
    powe[0]=1;
    f(i,1,512345){
        powe[i]=powe[i-1]*17;
        powe[i]%=mod;
    }
    while(t--){
    	// cout<<"Case #"<<t1-t<<": ";
        int n;
        cin>>n;
        int i=0;
        cin>>s;
        int cnt=0;
        while(i<n){
            if(i==n-1)
                break;
            if(s[i]=='('){
                i+=2;
                cnt++;
                continue;
            }
            lef=0,rig=0;
            int j;
            f(j,i+1,n){
                adder(i,j);
                if(lef==rig){
                    int p=i;
                    int q=j;
                    int flag=0;
                    while(p<q){
                        if(s[p]!=s[q]){
                            flag=1;
                            break;
                        }
                        p++;
                        q--;
                    }
                    if(flag){
                        continue;
                    }
                    break;
                }
            }
            if(j==n){
                break;
            }
            else{
                i=j+1;
                cnt++;
                continue;
            }

        }
        cout<<cnt<<" "<<n-i<<endl;



    }

    return 0;
}