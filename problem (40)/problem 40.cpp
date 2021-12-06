#include <iostream>

using namespace std;

int tedad(int n);

int a[1000010] = {};

int main() {
	
	int counter = 0;
	int eshare = 1;
	while (eshare < 1000001) {
		counter++;
		int tmp = counter;
		for (int i = tedad(counter) - 1; i >= 0; i--) {
			a[eshare + i] = tmp % 10;
			tmp /= 10;
		}
		eshare += tedad(counter);
	}
	cout << a[1] * a[10] * a[100] * a[1000] * a[10000] * a[100000] * a[1000000] << endl << clock() << endl;
	system("pause");
	return 0;
}
int tedad(int n) {
	int counter = 0;
	while(n) {
		counter++;
		n /= 10;
	}
	return counter;
}
