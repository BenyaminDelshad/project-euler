#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

const ll MOD = 1000 * 1000ll * 1000 * 1000 * 1000 * 10;
const ll MOD2 = 250;
ll ans, m[260260];
ll dp[250260][300];

ll pow(ll a, ll b) {
	if(b == 0) return 1ll;
	ll x = pow(a, b / 2);
	x = (x * x) % 250;
	if(b % 2 == 0)
		return x;
	x = (x * a) % 250;
	return x;
}
int main() {
	for(ll i = 1; i < 250251; ++i)
		m[i] = pow(i, i);
	dp[0][0] = 1;
	for(ll i = 1; i < 250251; ++i)
		for(ll j = 0; j < 250; ++j)
			dp[i][j] = (dp[i - 1][j] + dp[i - 1][(j + 250 - m[i]) % 250]) % MOD;
	cout << dp[250250][0] - 1 << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}

