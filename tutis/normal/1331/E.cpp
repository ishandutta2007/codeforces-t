/*input
27 27

*/
#pragma GCC optimize ("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef long double ld;
template<typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T, typename K>
using ordered_map = tree<T, K, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	string A = "..........................#.#.######.#................................................#.###.#.#.#..#.#####..........................................###.#...#...##.#....#..#.....................................####.#.#.#####....####.#.###.#.................................##......#.#.....####....#.#.#.##..............................#..##.#####.###.###.#..#.##...#..#.#...........................###..#..#......#.#...####..##.##.##.##........................######.##.##.###.###.###....##..#..#...###.....................############....#.....#...#.##..##.##.#..###...................####################.#######..####..##########.................################################################...............##################################################..............##################################################.............####################################################...........######################################################..........######################################################.........########################################################.......##########################################################........########################################################..........############...#..##############...#.#.#############.......##.....#########..#...###############.#.......########..........####.....#####...##.#...###############.##.##..#.##.......##...#######.....#...###..###..###########.#..#...##.........######..#########.....#..#..##.##...#########.##.#####..#....#########..############.##.###.....###..#######...#..#....###.###########..#########.....#...###.###...########.#.#####.#...#..#.########.############.###.#..#..#...#..######..#..#....##.###...####################...#..#.##.###.###.####.#.###.####..###...#.####################.######.####....#..#.#....#.#..#.####...###.####################.....#..#..###.###...#.#.##.##.#..#...#..#..#####################.##.####.##.###...#.###.....####.#.######.#####################...###..#..#...###.#..###.####..#.###...#...######################.....##.###.##.###.##.....#..##.##..#...#.#######################.##.#....#.#....#.#..#.#.##.#...##.##.########################....####.#.#.#.#.####.##.#..#.###..###...########################.#..#...###...####...#..##....#..##...#############################...###...#.##.##.##.##..#.###.#..#..##############################...#.######.....#######...#...################.################..#....#####.#.###########...#..##############..##############################....############################..###########################.#..#.#############################..#########################.#...################################...########################...#...#############################....#######..###################.###############################.....#######.#.################...#####################.#######......#######...#...###########..#.###########.#####.#....######......#######.#.#.#..#.#...##.#.##..#.#..#.##...##.....#.#######.......########...##.....#.......##...##......#.#..###.########.........#######.#..####.####.###..###....###.#####.#.#########..........##########.#..#..#...#.####.###.##.#.....#...#########...........########....##.##.#....#...#.#....###.#...##########.............#########.##...#####.##.#.#...#.##...#############..............#########..###..#.#...###...#.###..#...###########...............#########...####...###.##.####.####.############.................#########.##....#.#......#....#.##############...................############.#.####.##.##.#.##..############.....................#############....####....#....############........................####################.#################...........................####################################..............................################################.................................##############################.....................................########################..........................................####################................................................############..........................";
	int x, y;
	cin >> x >> y;
	if (A[x * 64 + y] == '.')
		cout << "OUT\n";
	else
		cout << "IN\n";
	return 0;
}