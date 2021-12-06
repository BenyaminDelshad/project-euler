#include <iostream>

using namespace std;

int main() {
	int a[1001] = {1};
	int b[1001] = {1};
	int c[1001] = {};
	int counter = 1;
	while (!(a[999])) {
		for (int i = 0; i < 1001; i++)
			c[i] = a[i] + b[i];
		for (int i = 0; i < 1000; i++)
			if (c[i] > 9) {
				c[i + 1] += c[i] / 10;
				c[i] = c[i] % 10;
			}
		for (int i = 0; i < 1001; i++) {
			a[i] = b[i];
			b[i] = c[i];
			c[i] = 0;		
		}
		counter++;
	}
	cout << counter << endl << clock() << endl;	
	system("pause");
	return 0;	
}
