#include <iostream>

using namespace std;

int main() {
	int n = 100;
	int a = n * (n + 1) / 2 * n * (n + 1) / 2 - n * (n + 1) * (2 * n + 1) / 6;
	if (a < 0)
		a *= -1;
	cout << a << endl << clock() << endl;
	system("pause");
	return 0;
}
