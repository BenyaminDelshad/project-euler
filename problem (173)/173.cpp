#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll ans, n = 1000 * 1000;

int main() {
	for(ll i = 1; i <= n; i += 2)
		for(ll j = i - 2; j > 0; j -= 2)
			if(i * i - j * j <= n) ans++;
			else break;	
	for(ll i = 2; i <= n; i += 2)
		for(ll j = i - 2; j > 0; j -= 2)
			if(i * i - j * j <= n) ans++;
			else break;
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
