#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
typedef long long ll;

bool prime[1000 * 1000 * 100];
vector<ll>p;
ll n = 1000 * 1000 * 10;

int main() {
	fill(prime + 2, prime + n + 1, true);
	for(ll i = 2; i <= n; ++i)
		if(prime[i])
			for(ll j = i * i; j <= n; j += i)
				prime[j] = false;
	for(ll i = 2; i <= n; ++i)
		if(prime[i]) p.pb(i);
	ll ans = 0;
	int sz = p.size();
	//cerr << sz << endl;
	for(ll i = 0; i < sz; ++i) {
		//if(i % 1000 == 0) cerr << i / 1000 << endl;
		for(ll j = i + 1; p[i] * p[j] <= n && j < sz; ++j) {
			set<ll>s;
			s.insert(p[i] * p[j]);
			ll r;
			while(!s.empty() ) {
				r = *s.begin();
				s.erase(s.begin() );
				if(r * p[i] <= n)
					s.insert(r * p[i]);
				if(r * p[j] <= n)
					s.insert(r * p[j]);
			}
			ans += r;
		}
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
