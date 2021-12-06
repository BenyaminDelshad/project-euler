#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;

ll ans;

int main() {
	for(int a = 3; a <= 1000; ++a) {
		ll Max = 2;
		for(int n = 1; n <= a * a; n += 2)
			Max = max(Max, (ll)(2 * n * a) % (a * a));
		ans += Max;
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
