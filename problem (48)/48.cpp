#include<iostream>

using namespace std;

int main(){
	long long ans = 0;
	for(int i = 1; i <= 1000; i++){
		long long tmp = 1;
		for(int j = 0; j < i; j++){
			tmp = (long long)tmp * i;
			tmp = tmp % ((long long)100000 * 100000);
		}
		ans = (long long)ans + tmp;
		ans = ans % ((long long)100000 * 100000);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
