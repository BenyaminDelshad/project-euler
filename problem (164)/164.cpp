#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll dp[25][25][25];
ll dp2[25];

int main() {
	for(ll i = 0; i < 10; ++i)
		for(ll j = 0; j < 10; ++j)
			if(i + j < 10)
				dp[2][i][j]++;
	
	for(ll i = 3; i < 21; ++i) 
		for(ll j = 0; j < 10; ++j) 
			for(ll k = 0; k < 10; ++k) 
				for(ll t = 9 - j - k; t >= 0; --t)
					dp[i][k][t] += dp[i - 1][j][k];
		
	for(ll i = 2; i < 21; ++i)
		for(ll j = 0; j < 10; ++j)
			for(ll k = 0; k < 10; ++k)
				dp2[i] += dp[i][j][k];	
	
	cout << dp2[20] - dp2[19] << endl;
	
	system("pause");
	return 0;
}
