#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#define pb push_back
using namespace std;
typedef long long ll;

vector<ll>pr;
set<ll>s;
ll ans;

bool is_prime(int p) {
	if(p == 2) return true;
	if(p % 2 == 0 || p == 1) return false;
	for(int i = 3; i * i <= p; i += 2)
		if(p % i == 0) return false;	
	return true;
}
int main() {
	for(int i = 1; i < 101; ++i)
		if(is_prime(i))
			pr.pb(i);
	s.insert(1ll);
	while(!s.empty()) {
		ll tmp = *s.begin();
		ans++;
		s.erase(s.begin());
		for(ll i = 0; i < pr.size(); ++i)
			if((ll)tmp * pr[i] <= 1000 * 1000 * 1000)
				s.insert((ll)tmp * pr[i]);
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
