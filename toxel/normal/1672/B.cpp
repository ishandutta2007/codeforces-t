//
// Created by  on 2022/4/23.
//

//
// Created by  on 2022/1/6.
//

#ifndef WORKSPACE_TEMPLATE_H
#define WORKSPACE_TEMPLATE_H

#include <bits/stdc++.h>
#define mp std::make_pair
#define scanf dont_use_scanf
#define printf dont_use_printf
#define puts dont_use_puts
#define endl dont_use_endl

using ll = int64_t;
using i128 = __int128_t;
using pii = std::pair <int, int>;
using piii = std::tuple <int, int, int>;
using piiii = std::tuple <int, int, int, int>;
using pll = std::pair <ll, ll>;
using plll = std::tuple <ll, ll, ll>;
using pllll = std::tuple <ll, ll, ll, ll>;

class Solver{
public:
    void solve(){
        std::string s;
        std::cin >> s;
        int n = s.size();
        if (s.back() == 'A'){
            std::cout << "NO\n";
            return;
        }
        int cnta = 0, cntb = 0;
        for (int i = 0; i < n; ++ i){
            cnta += s[i] == 'A';
            cntb += s[i] == 'B';
            if (cntb > cnta){
                std::cout << "NO\n";
                return;
            }
        }
        std::cout << "YES\n";
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);
    int test;
    std::cin >> test;
    while (test --){
        Solver solver;
        solver.solve();
    }
    // floating point number output template
    std::cout << std::fixed << std::setprecision(18) << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H