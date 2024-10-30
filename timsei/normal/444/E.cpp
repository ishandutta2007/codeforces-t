#include <bits/stdc++.h>
using namespace std;const int N = 3e3 + 5;int fa[N] , S[N] , Q[N] , n , m , x , y , w , All;bool bad_blood = 0;struct Edge {int x , y;};vector <Edge> W[(int)1e4 + 5];int getf(int x) {return (fa[x] == x) ? x : (fa[x] = getf(fa[x]));}void merge(int x , int y) {x = getf(x);y = getf(y);if(S[x] < S[y])swap(x , y);S[x] += S[y];Q[x] += Q[y];fa[y] = x;if(All - Q[x] < S[x]) bad_blood = 1;}main(void) {scanf("%d" , &n);for(int i = 1;i < n;++ i) {scanf("%d%d%d" , &x , &y , &w);W[w].push_back((Edge){x , y});}int ans = 0;for(int i = 1;i <= n;++ i) {fa[i] = i;S[i] = 1;scanf("%d" , &Q[i]);All += Q[i];}for(int i = 1;i <= n;++ i)if(All - Q[i] < S[i]) bad_blood = 1;for(int i = 0;i < 1e4 + 5;++ i)if(W[i].size()) {if(!bad_blood) ans = i;for(auto V : W[i]) merge(V.x , V.y);if(bad_blood) break;}cout << ans << endl;}