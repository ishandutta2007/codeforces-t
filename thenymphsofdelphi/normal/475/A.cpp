#include<bits/stdc++.h>
using namespace std;

string s[6] = {"+------------------------+",
               "|#.#.#.#.#.#.#.#.#.#.#.|D|)",
               "|#.#.#.#.#.#.#.#.#.#.#.|.|",
               "|#.......................|",
               "|#.#.#.#.#.#.#.#.#.#.#.|.|)",
               "+------------------------+"};
pair <int, int> a[35] = {{1, 1},
                         {2, 1},
                         {3, 1},
                         {4, 1},
                         {1, 3},
                         {2, 3},
                         {4, 3},
                         {1, 5},
                         {2, 5},
                         {4, 5},
                         {1, 7},
                         {2, 7},
                         {4, 7},
                         {1, 9},
                         {2, 9},
                         {4, 9},
                         {1, 11},
                         {2, 11},
                         {4, 11},
                         {1, 13},
                         {2, 13},
                         {4, 13},
                         {1, 15},
                         {2, 15},
                         {4, 15},
                         {1, 17},
                         {2, 17},
                         {4, 17},
                         {1, 19},
                         {2, 19},
                         {4, 19},
                         {1, 21},
                         {2, 21},
                         {4, 21}};

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        s[a[i].first][a[i].second] = 'O';
    }
    for (int i = 0; i < 6; i++){
        cout << s[i] << endl;
    }
}