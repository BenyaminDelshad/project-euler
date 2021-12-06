#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long a = 1;
	for(int i = 0; i < 7830457; i++){
		a = (long long)a * 2;
		a %= (10000000000ll);
	}
	a = (long long) a *  28433 + 1;
	a %= (10000000000ll);
	cout << a << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
