#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;

int dp[110][110], dp2[110];
vector<int>pr;

bool is_prime(int p) {
	if(p == 2) return true;
	if(p % 2 == 0 || p == 1) return false;
	for(int i = 3; i * i <= p; i += 2)
		if(p % i == 0) return false;	
	return true;
}
int main() {
	pr.pb(0);
	for(int i = 1; i < 101; ++i)
		if(is_prime(i))
			pr.pb(i);
	dp[0][0] = 1;
	for(int i = 1; i < 101; ++i) {
		for(int j = 1; j < pr.size() && pr[j] <= i; ++j) {
			for(int k = 1; k * pr[j] <= i; ++k) {
				for(int t = j - 1; t >= 0; --t) {
					dp[i][j] += dp[i - k * pr[j]][t];	
				}
			}
		}	
	}
	for(int i = 1; i < 101; ++i)
		for(int j = 1; j < pr.size(); ++j)
			dp2[i] += dp[i][j];
	int ans = 1;
	while(dp2[ans] <= 5000) ++ans;
	cout << ans << endl;
	cout << "Time: " << ' ' << clock() << " mS" << endl;
	system("pause");
	return 0;
}
