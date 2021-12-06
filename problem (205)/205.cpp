#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;
typedef long double ld;
typedef long long ll;

ll t1[40], t2[40];
ll t11[40], t22[40];
ll ans;

int main() {
	for(int i = 0; i < 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4 * 4; ++i) {
		ll tmp[9] = {}, tmp2 = i, s = 0;
		for(int j = 0; j < 9; ++j) {
			tmp[j] = tmp2 % 4;
			tmp2 /= 4;
			s += (tmp[j] + 1);
		}
		t1[s]++;
	}
	for(int i = 0; i < 6 * 6 * 6 * 6 * 6 * 6; ++i) {
		ll tmp[6] = {}, tmp2 = i, s = 0;	
		for(int j = 0; j < 6; ++j) {
			tmp[j] = tmp2 % 6;
			tmp2 /= 6;
			s += (tmp[j] + 1);
		}
		t2[s]++;
	}
	for(int i = 1; i < 37; ++i) {
		t11[i] = t11[i - 1] + t1[i];
		t22[i] = t22[i - 1] + t2[i];
	}
	for(int i = 1; i < 37; ++i) {
		ans += (ll) (t1[i] * t22[i - 1]);	
	}
	//cout << ans << ' ' << 4 * 4ll * 4 * 4ll * 4 * 4 * 4ll * 4 * 4 * 6ll * 6 * 6 * 6 * 6 * 6 << endl;
	ld tmp = (ld)ans / (4 * 4ll * 4 * 4ll * 4 * 4 * 4ll * 4 * 4 * 6ll * 6 * 6 * 6 * 6 * 6);
	cout << setprecision(7) << tmp << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
