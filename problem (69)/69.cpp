#include <iostream>
#include <algorithm>
using namespace std;

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

int main(){
	int Max = 0;
	long double x = 0;
	for(int i = 1; i <= 1000000; i++)
		if((double)i / t(i) > x){
			x = (double)i / t(i);
			Max = i;
		}
	cout << Max << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
