//
// Created by  on 2022/3/24.
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
        int n;
        std::cin >> n;
        std::vector <int> a(n);
        std::map <int, int> map;
        for (int i = 0; i < n; ++ i){
            std::cin >> a[i];
            ++ map[a[i]];
        }
        if (map[1] == 0){
            std::cout << "YES\n";
            return;
        }
        for (const auto &p: map){
            if (p.second > 0 && map.count(p.first + 1) && map[p.first + 1] > 0){
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
    // std::cout << std::fixed << std::setprecision(18) << 1.0 << '\n';
    return 0;
}

#endif //WORKSPACE_TEMPLATE_H