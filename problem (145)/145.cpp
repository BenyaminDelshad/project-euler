#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
using namespace std;
typedef long long ll;

bool check(ll n) {
	int p = 0;
	ll a[10];
	ll tmp = n;
	while(tmp) {
		a[p++] = tmp % 10;
		tmp /= 10;
	}
	ll tmp2 = 0;
	for(int i = 0; i < p; ++i) {
		tmp2 *= 10ll;
		tmp2 += (ll) a[i];
	}
	tmp2 += n;
	while(tmp2) {
		ll t = tmp2 % 10;
		if(t % 2 == 0) return false;
		tmp2 /= 10;
	}
	return true;
}
int main() {
	ll ans = 0;
	for(int i = 1; i < 1000 * 1000 * 1000; ++i) {
		if(i % 10000000 == 0) cerr << i / 10000000 << endl;
		if(i % 10 == 0) continue;
		if(check(i)) ans++;
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
