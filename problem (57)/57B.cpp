#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;

ll x[5000], y[5000], ans;

int main() {
	x[0] = 1, y[0] = 1;
	for(int j = 0; j < 1000; ++j) {
		ll tmp2[5000] = {}, tmp[5000] = {};
		for(int i = 0; i < 5000; ++i)
			tmp2[i] = x[i] + y[i];
		for(int i = 0; i < 4999; ++i) {
			tmp2[i + 1] += (tmp2[i] / 10);
			tmp2[i] %= 10;
			tmp[i] = tmp2[i];
		}
		for(int i = 0; i < 4999; ++i)
			tmp[i] += y[i];
		for(int i = 0; i < 4998; ++i) {
			tmp[i + 1] += (tmp[i] / 10);
			tmp[i] %= 10;
		}
		for(int i = 0; i < 4998; ++i) {
			x[i] = tmp[i];
			y[i] = tmp2[i];
		}
		ll len1 = 4999, len2 = 4999;
		while(!x[len1]) len1--;
		while(!y[len2]) len2--;
		if(len1 != len2)
			ans++;	
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
