#include <bits/stdc++.h>

const int N = 110;

int a[N];

void solve(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i){
        scanf("%d", &a[i]);
        if (i & 1){
            if (a[i] > 0){
                a[i] = -a[i];
            }
        }
        else{
            if (a[i] < 0){
                a[i] = -a[i];
            }
        }
    }
    for (int i = 0; i < n; ++ i){
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
}

int main(){
    int test;
    scanf("%d", &test);
    while (test --){
        solve();
    }
    return 0;
}