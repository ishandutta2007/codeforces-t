#include <bits/stdc++.h>
using namespace std;int main() {int n,m;cin>>n>>m;bool used[n]={0};set<pair<long long,int> > d;long long is[n];int pr[n]={-1};for(int i=0;i<n;++i) {is[i]=((bool) i)*((long long) 1e18);d.insert({is[i],i});} vector <pair<int,int> > a[n];for(int i=0;i<m;++i) {int x,y,w;cin>>x>>y>>w;--x;--y;a[x].push_back({y,w});a[y].push_back({x,w});} while(!d.empty()) {pair<int,int> o=(*d.begin());d.erase(d.begin());int x=o.second;used[x]=true;for(auto h:a[x]) {auto [v,w]=h;if(is[v]>is[x]+w && !used[v]) {pr[v]=x;d.erase({is[v],v});is[v]=min(is[v],is[x]+w);d.insert({is[v],v});}}} if(is[n-1]==1e18) {cout<<(-1);return 0;} else {vector <int> res;int cur=n-1;while(cur!=(-1)) {res.push_back(cur);cur=pr[cur];} reverse(res.begin(),res.end());for(auto h:res) cout<<h+1<<' ';}}