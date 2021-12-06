#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

bool mark[1000 * 1000 + 1000];
int p[1000 * 100 * 2];
int sz;
ll ans;

int main() {
	mark[1] = true;
	for(ll i = 2; i <= 1000 * 1000 + 100; ++i)
		if(!mark[i])
			for(ll j = i * i; j <= 1000 * 1000 + 100; j += i)
				mark[j] = true;
	for(int i = 1; i < 1000 * 1000; ++i)
		if(!mark[i])
			p[sz++] = i;
	int r = 1000000;
	while(mark[r]) r++;
	p[sz++] = r;
	for(int i = 2; i < sz - 1; ++i) {
		//if(i % 1000 == 0) cerr << i / 1000 << endl;
		ll s = p[i];
		ll t = 0, tmp = p[i], pow = 1;
		while(tmp) {
			t++;
			tmp /= 10;
		}
		for(int j = 0; j < t; ++j)
			pow *= 10;
		for(s; ; s += pow) {
			if(s % p[i + 1] == 0) {
			//	if(i % 1000 == 0) cerr << s << endl;
				ans += s;
				break;
			}
		}
	}
	
	cout << ans << endl;
	system("pause");
	return 0;
}
