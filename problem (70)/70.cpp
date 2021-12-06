#include <iostream>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
typedef long long ll;

int phi[1000 * 1000 * 10 + 10];
int Min = 2;
vector<int>p[1000 * 1000 * 10 + 10];
bool mark[1000 * 1000 * 10 + 10];

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
bool check(int k) {
	int tmp[2] = {k, phi[k]};
	int t[2][10] = {};
	for(int i = 0; i < 2; ++i)
		while(tmp[i]) {
			t[i][tmp[i] % 10]++;
			tmp[i] /= 10;
		}
	for(int i = 0; i < 10; ++i)
		if(t[0][i] != t[1][i]) return false;
	return true;
}

int main() {
	phi[1] = 1;
	mark[1] = true;
	for(int i = 2; i <= 1000 * 1000 * 10; ++i)
		if(!mark[i]) {
			mark[i] = true;
			for(int j = i; j <= 1000 * 1000 * 10; j += i){
				p[j].push_back(i);
				mark[j] = true;
			}
		}
	for(int i = 2; i <= 1000 * 1000 * 10; ++i)
		phi[i] = t(i);
	while(!check(Min)) Min++;
	cerr << Min << endl; 
	for(int i = 2; i <= 1000 * 1000 * 10; ++i)
		if((long long)phi[i] * Min > (long long) i * phi[Min] && check(i))
			Min = i;
	cout << Min << endl;
	cout << "Time: " << clock() << " mS" <<endl;
	system("pause");
	return 0;
}
