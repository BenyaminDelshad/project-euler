#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[115][115], n = 100, ans;

int main() {
	for(int i = 0; i <= 101; ++i)
		dp[0][i] = 1;
	for(int i = 1; i <= 9; ++i)
		for(int j = 1; j <= 110; ++j)
			dp[i][j] = (ll)dp[i - 1][j - 1] + dp[i][j - 1];
	for(ll i = 1; i <= n; ++i)
		ans += (dp[8][8 + i] + dp[9][9 + i] - 10);
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
