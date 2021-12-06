#include <iostream>
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;
typedef long long ll;

int n = 80;
ifstream fin("matrix.txt");
ll arr[80][80], sum[80][80][80], dp[80][80][80][80];

int main() {
	ll tmp;
	char c;
	for(int i = 0; i < 80; ++i)
		for(int j = 0; j < 80; ++j)
			if(j < 79)
				fin >> arr[i][j] >> c;
			else
				fin >> arr[i][j];
	for(int i = 0; i < 80; ++i)
		for(int j = 0; j < 80; ++j) {
			sum[i][j][j] = arr[j][i];
			for(int k = j + 1; k < 80; ++k) {
				sum[i][j][k] = sum[i][j][k - 1] + arr[k][i];
				sum[i][k][j] = sum[i][j][k];
			}				
		}
	for(int i = 0; i < 80; ++i)
		for(int j = 0; j < 80; ++j)
			for(int k = 0; k < 80; ++k)
				dp[i][j][k][j] = sum[j][i][k];
	for(int j = 0; j < 80; ++j)
		for(int i = 0; i < 80; ++i)
			for(int t = j + 1; t < 80; ++t)   
				for(int k = 0; k < 80; ++k) {
					dp[i][j][k][t] = 1000 * 1000ll * 1000 * 1000;
					for(int l = 0; l < 80; ++l)
						dp[i][j][k][t] = min(dp[i][j][k][t], sum[t][l][k] + dp[i][j][l][t - 1]);
				}
	ll ans = 1000 * 1000ll * 1000 * 1000 * 1000;
	for(int i = 0; i < 80; ++i)
		for(int j = 0; j < 80; ++j)
			ans = min(ans, dp[i][0][j][79]);
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
