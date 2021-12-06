#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	for (long long i = 100000000; i < 150000000; i++){
		long long tmp = (long long) i * i;
		long long tmp2 = (long long) tmp;
		int a[20];
		for(int i = 17; i > 0; i--){
			a[i] = tmp2 % 10;
			tmp2 /= 10;
		}
		bool x = true;
		for(int i = 1; i < 10; i++)
			if(a[2 * i - 1] != i)
				x = false;
		if(x){
			cout << i <<  0 << endl;
			break;
		}
	} 
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
