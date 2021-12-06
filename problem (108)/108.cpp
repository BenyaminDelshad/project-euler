#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
	for(ll i = 1; ; ++i) {
		//if(i % 1000 == 0) cerr << i / 1000 << endl;
		int ans = 0;
		for(ll j = i + 1; j <= 2 * i; ++j)
			if((i * j) % (j - i) == 0) ans++;
		if(ans > 1000) {
			cout << i << endl;
			break;
		}
	}	
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
