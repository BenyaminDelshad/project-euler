#include <iostream>

using namespace std;

int fib(int k);

int main() {
	int sum = 0;
	for	(int i = 3; fib(i) <= 4000000; i += 3)
		sum += fib(i);
	cout << sum << endl << clock() << endl;		
	system("pause");
	return 0;
}
int fib(int k) {
	int a[35];
	a[0] = 0;
	a[1] = 1;
	for(int i = 2; i <= k; i++)
		a[i] = a[i - 1] + a[i - 2];
	return a[k];
}
