#include <iostream>
#include <algorithm>
#include <vector>
#define pb push_back
using namespace std;
typedef long long ll;

const ll MOD = 1000 * 1000 * 1000 + 9;
const ll N = 1000 * 1000 * 100;
bool prime[N + 5];
int me[N + 5];
int p[N + 5];
ll po[N + 5];
vector<ll>pr;

ll pow(ll a, ll b) {
	if(b == 0) return 1;
	if(b == 1) return a;
	ll r = pow(a, b / 2);
	ll t = (r * r) % MOD;
	if(b % 2)
		t = (t * a) % MOD;
	return t;
}
int main() {
	for(int i = 2; i < N + 1; ++i) {
		prime[i] = true;
		p[i] = 1;
	}
	prime[0] = prime[1] = false;
	for(ll i = 2; i <= N; ++i) {
		if(i % 1000000 == 0) cerr << i / 1000000 << endl;	
		if(prime[i])
			for(ll j = i * i; j <= N; j += i) {
				prime[j] = false;
				if(me[j] == 0) me[j] = i;
			}
	}
	for(ll i = 1; i <= N; ++i)
		if(prime[i])
			pr.pb(i);
	for(ll i = N; i > 1; --i) {
		if(prime[i] || p[i] == 0) continue;
		p[me[i]] += p[i];
		p[i / me[i]] += p[i];
		p[i] = 0;
	}
	ll ans = 1;
	for(ll i = 2; i <= N; ++i) {
		if(prime[i]) {
			p[i] *= 2;
			po[i] = (pow(i, p[i]) + 1) % MOD;
			ans = (ans * po[i]) % MOD;
		}
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
