#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
typedef long long ll;

struct triple{
	ll x, y, z;
};
set<triple>s;

bool operator<(triple a, triple b) {
	if(a.x != b.x)
		return a.x < b.x;
	if(a.y != b.y)
		return a.y < b.y;
	return a.z < b.z;
}

int main() {
	ll cnt = 0, ans = 0;
	for(ll i = 3; cnt < 124; i += 2) {
		bool flag = false;
		s.clear();
		ll b1 = 1, b2 = 1, b3 = 1;
		triple t;
		t.x = b1;
		t.y = b2;
		t.z = b3;
		s.insert(t);
		for(ll j = 1; j < (i - 1) * (i - 1) * (i - 1) + 3; ++j) {
			ll tmp = (b3 + b2 + b1) % i;
			if(!tmp) {
				flag = true;
				break;
			}
			b1 = b2;
			b2 = b3;
			b3 = tmp;
			triple tt;
			tt.x = b1;
			tt.y = b2;
			tt.z = b3;
			if(s.find(tt) != s.end() )
				break;
			s.insert(tt);
		}
		if(flag) continue;
		cnt++;
		ans = i;
	}
	cout << ans << endl;
	system("pause");	
	return 0;
}
