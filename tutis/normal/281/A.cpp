/*input
1987
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
bool NonDistinct(int x)
{
	set<int>Y;
	while (x > 0)
	{
		Y.insert(x % 10);
		x /= 10;
	}
	return Y.size() != 4;
}
int main()
{
	ios_base::sync_with_stdio(false);
	string A;
	cin >> A;
	A[0] = toupper(A[0]);
	cout << A << "\n";
}