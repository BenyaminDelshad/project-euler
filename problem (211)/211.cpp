#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;

bool prime[1000 * 1000 * 65];
ll p[64 * 1000 * 1000 + 10];
ll n = 64 * 1000 * 1000;

int main() {
	for(ll i = 1; i < 1000 * 1000 * 64; ++i) {
		//if(i % 1000000 == 0) cerr << i / 1000000 << endl;
		for(ll j = i ; j < 1000 * 1000 * 64; j += i)
			p[j] += (ll)(i * i);
	}
	ll ans = 0;
	for(ll i = 1; i < n; ++i) {
		//if(i % 1000000 == 0) cerr << i / 1000000 << endl;
		ll t = (ll)sqrt(p[i]);
		if((ll) t * t == p[i]) ans+= i;
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
