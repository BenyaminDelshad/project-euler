#include <iostream>
#include <algorithm>
#include <ctime>
#include <cmath>
using namespace std;
typedef long long ll;

bool prime[1000 * 1000 * 100 * 2 + 10];
ll p[100 * 1000 * 1000 + 10];
ll t[100 * 1000 * 1000 + 10];
ll n = 100 * 1000 * 1000;

int main() {
	fill(prime + 2, prime + n + 5, true);
	for(ll i = 2; i <= n + 4; ++i) {
		//if(i % 100000 == 0) cerr << i / 100000 << endl;
		if(prime[i])
			for(ll j = i * i; j <= n + 4; j += i)
				prime[j] = false;
	}
	for(ll i = 1; i <= n; ++i) {
		//if(i % 100000 == 0) cerr << i / 100000 << endl;
		for(ll j = i ; j <= n; j += i) {
			t[j]++;
			if(prime[i + j / i]) p[j]++;
		}
	}
	ll ans = 0;
	for(ll i = 1; i <= n; ++i)
		if(t[i] == p[i]) ans += i;
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
