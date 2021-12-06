#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;

int phi[1000 * 1000 * 10 * 2 + 10];
vector<int>p[1000 * 1000 * 10 * 2 + 10];
bool mark[1000 * 1000 * 10 * 2 + 10];

ll t(ll n){
	ll sorat = 1;
	ll makhraj = 1;
	ll nn = n;
	for(int i = 0; i < p[n].size(); i++) {
		sorat *= (p[n][i] - 1);
		makhraj *= p[n][i];
	}
	nn /= makhraj;
	nn *= sorat;
	return nn;	
}

int main() {
	phi[1] = 1;
	mark[1] = true;
	for(int i = 2; i <= 1000 * 1000 * 10 * 2; ++i) {
		if(i % 100000 == 0) cerr << i << endl;	
		if(!mark[i]) {
			mark[i] = true;
			for(int j = i; j <= 1000 * 1000 * 10 * 2; j += i){
				p[j].push_back(i);
				mark[j] = true;
			}
		}
	}
	ll Min = 1, Max = 1;
	for(int i = 2; i <= 1000 * 1000 * 10 * 2; ++i) {
		if(i % 100000 == 0) cerr << i << endl;
		phi[i] = t(i);
		if((ll) phi[i] * Max < (ll)(i - 1) * Min) {
			Min = phi[i];
			Max = i - 1;
		}
		if((ll) phi[i] * 94744 < (ll)(i - 1) * 15499) {
			cout << i << endl;
			break;
		}
	}
	cerr << Min << " / " << Max << endl;
	cerr << phi[1000 * 1000 * 10 -1] << " / " << (1000 * 1000 * 10 - 1) << endl;
	cout << "Time: " << clock() << " mS" <<endl;
	system("pause");
	return 0;
}
