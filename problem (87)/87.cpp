#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

bool is[50 * 1000 * 1000 + 10];
vector<ll>p;

bool is_prime(ll n) {
	if(n == 2) return true;
	if(n % 2 == 0) return false;
	for(ll i = 3; i * i <= n; i += 2)
		if(!(n % i)) return false;
	return true;
}

int main() {
	for(int i = 2; i < 7100; ++i)
		if(is_prime(i))
			p.push_back(i);
	int sz = p.size();
	ll tmp = 0;
	for(int i = 0; i < sz; ++i) {
		tmp += (ll)p[i] * p[i];
		for(int j = 0; j < sz; ++j) {
			tmp += (ll)p[j] * p[j] * p[j];
			for(int k = 0; k < sz; ++k) {
				tmp += (ll)p[k] * p[k] * p[k] * p[k];
				if(tmp < 50 * 1000 * 1000) is[tmp] = true;
				tmp -= (ll)p[k] * p[k] * p[k] * p[k];
			}
			tmp -= (ll)p[j] * p[j] * p[j];
		}
		tmp -= (ll)p[i] * p[i];
	}
	ll ans = 0;
	for(int i = 1; i < 50 * 1000 * 1000; ++i)
		if(is[i]) ans++;
	cout << ans << endl;
	cerr << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
