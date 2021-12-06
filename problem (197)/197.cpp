#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
using namespace std;
typedef long double ld;

ld U[10000000];
const ld n = pow(2, (ld)30.403243784 );

int main() {
	U[0] = -1;
	for(int i = 1; i < 2000000; ++i) {
		U[i] = n / pow(2, U[i - 1] * U[i - 1] );
		U[i] = (int) U[i];
		U[i] *= (1e-9);
		if(i == 2000000 - 1 && i % 2 == 1) cerr << fixed << setprecision(9) << U[i] + U[i - 1] << endl;
	}
	
	system("pause");
	return 0;
}
