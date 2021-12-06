#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[60];

int main() {
	dp[0] = dp[1] = 1;
	dp[2] = 2;
	dp[3] = 4;
	dp[4] = 8;
	for(int i = 5; i < 51; ++i)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3] + dp[i - 4];
	cout << dp[50] << endl;
	system("pause");
	return 0;
}
