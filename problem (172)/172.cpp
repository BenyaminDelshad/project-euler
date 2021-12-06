#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll ans, C[20][20];

int main() {
	for(ll i = 0; i < 20; ++i) {
		C[0][i] = 1;
		C[1][i] = i;
		C[2][i] = i * (i - 1) / 2;
		C[3][i] = i * (i - 1) * (i - 2) / 6;
	}
	for(int i = 0; i < (1<<20); ++i) {
		int t[10], tmp = i, sigma = 0;
		for(int j = 0; j < 10; ++j) {
			t[j] = tmp % 4;
			sigma += t[j];
			tmp /= 4;
		}
		if(sigma != 18) continue;
		ll ans2 = C[t[0]][17], r = 18 - t[0];
		for(int j = 1; j < 10; ++j) {
			ans2 *= (ll) C[t[j]][r];
			r -= t[j];
		}
		ans += (ll) ans2;
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
