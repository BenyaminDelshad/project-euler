#include <iostream>

using namespace std;

int main() {
	long long int c = 1;
	for (int i = 21; i < 40; i += 2)
		c *= i;
	c *= 1024;
	int b = 1;
	for(int i = 2; i <= 10; i += 1)
		b *= i;
	cout << c / b << endl;
	system("pause");
	return 0;
}
