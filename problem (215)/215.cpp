#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#define pb push_back
using namespace std;
typedef long long ll;
vector<ll>v;
ll dp[12][3500], ans;

int main() {
	for(int i = 0; i <= (1<<30) - 1; ++i) {
		if(i % 2 == 1) continue;
		bool flag = true;
		for(int j = 0; j < 29; ++j)
			if(!(((i>>j) & 1) | ((i>>(j+1)) & 1) | ((i>>(j+2)) & 1))) {
				flag = false;
				break;
			}
		if(!flag) continue;
		for(int j = 0; j < 30; ++j) 
			if((i>>j) & 1 == 1 && (i>>(j+1)) & 1 == 1) {
				flag = false;
				break;
			}
		if(!flag) continue;
		v.pb( (ll) i);
	}
	for(int i = 0; i < v.size(); ++i)
		dp[1][i] = 1;
	for(int i = 2; i < 11; ++i)
		for(int j = 0; j < v.size(); ++j)
			for(int k = 0; k < v.size(); ++k)
				if( ! (v[j] & v[k]) )
					dp[i][j] += (ll) dp[i - 1][k];
	for(int i = 0; i < v.size(); ++i)
		ans += dp[10][i];
	cout << ans << endl;	
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
