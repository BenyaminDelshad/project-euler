#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll ans;
int main() {
	for(int i = 1; i <= (1<<30); ++i) {
		ll a = (ll)i;
		ll b = a * 2;
		ll c = a * 3;
		a ^= b;
		a ^= c;
		if(a == 0) ans++;
	}	
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
