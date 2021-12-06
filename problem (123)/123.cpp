#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#define pb push_back
using namespace std;
typedef long long ll;

bool prime[1000 * 1000 * 100];
vector<ll>p;

ll pow(ll a, ll b, ll mod) {
	if(b == 0) return 1ll;
	if(b == 1) return (a % mod);
	ll t = 1;
	for(ll i = 0; i < b; ++i)
		t = (ll) (t * a) % mod;
	return t;
	/*a %= mod;
	ll t = pow(a, b / 2, mod);
	ll t2 = (t * t) % mod;
	if(b % 2)
		t2 = (t2 * a) % mod;
	return t2;*/	
}
int main() {
	fill(prime + 2, prime + 1000 * 1000 * 10 + 1, true);
	for(ll i = 2; i <= 1000 * 1000 * 10; ++i)
		if(prime[i])
			for(ll j = i * i; j <= 1000 * 1000 * 10; j += i)
				prime[j] = false;
	p.pb(1);
	for(ll i = 2; i <= 1000 * 1000 * 10; ++i)
		if(prime[i]) p.pb(i);
	for(ll i = 7038; i < p.size(); i++) {
		ll tmp = (pow(p[i] - 1, i, (ll) p[i] * p[i]) + pow(p[i] + 1, i, (ll) p[i] * p[i]) ) % ((ll) p[i] * p[i]);
		if(i == 3 || i == 7037) cerr << tmp << endl;
		if(tmp > 1000 * 1000ll * 10000) {
			cout << i << ' ' << p[i] << ' ' << tmp << endl;
			break;
		}
	}
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
