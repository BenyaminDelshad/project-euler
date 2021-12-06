#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

set<ll>s;

int main() {
	for(ll i = 2; i < 1000 * 1000 * 2; ++i) {
		//if(i % 100000 == 0) cerr << i / 100000 << endl;
		ll tmp = 1;
		while(tmp < 1000 * 1000ll * 1000 * 1000 * 4) {
			tmp *= i;
			if(tmp < 10) continue;
			ll tmp2 = tmp, r = 0;
			while(tmp2) {
				r += tmp2 % 10;
				tmp2 /= 10;
			}
			if(r == i) s.insert(tmp);
		}
	}
	for(int i = 0; i < 29; ++i) {
		s.erase(s.begin());
	}
	cout << *s.begin() << endl;
	cout << "Time: " << clock() << " mS" << endl;	
	system("pause");
	return 0;
}
