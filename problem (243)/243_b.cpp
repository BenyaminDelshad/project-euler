#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int t(int n){
	int sorat = 1;
	int makhraj = 1;
	int nn = n;
	for(int i = 2; i * i <= n; i++)
		if(!(n % i)){
			while(!(n % i))
				n /= i;
			sorat *= (i - 1);
			makhraj *= i;
		}
	if(n != 1){
		sorat *= (n - 1);
		makhraj *= n;
	}
	nn /= makhraj;
	nn *= sorat;
	return nn;	
}

int main() {
	int k = 2 * 3 * 5 * 7 * 11;
	for(int i = ((100000000 / k) + 1) * k; i < 1000 * 1000 * 1000; i += k)
		if((ll) t(i) * 94744 < (ll)(i - 1) * 15499) {
			cout << i << endl;
			break;
		}
	cout << "Time: " << clock() << " mS" <<endl;
	system("pause");
	return 0;
}
