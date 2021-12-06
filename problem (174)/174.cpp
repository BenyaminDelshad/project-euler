#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll ans, n = 1000 * 1000;
ll t[1000 * 1000 + 10];
ll N[20];

int main() {
	for(ll i = 1; i <= n; i += 2)
		for(ll j = i - 2; j > 0; j -= 2)
			if(i * i - j * j <= n) t[i * i - j * j]++;
			else break;	
	for(ll i = 2; i <= n; i += 2)
		for(ll j = i - 2; j > 0; j -= 2)
			if(i * i - j * j <= n) t[i * i - j * j]++;
			else break;
	for(int i = 1; i < 11; ++i)
		for(int j = 1; j <= n; ++j)
			if(t[j] == i) N[i]++;
	for(int i = 1; i < 11; ++i)
		ans += N[i];
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
