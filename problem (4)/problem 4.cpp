#include <iostream>

using namespace std;

bool ayne(int n);

int main() {
	int x = 0;
	for (int i = 999; i  >= 100; i--)
		for (int j = 999; j >= 100; j--)
			if ((i * j > x) && ayne(i * j))
				x = i * j;
	cout << x << endl << clock() << endl; 
	system("pause");
	return 0;
}
bool ayne(int n) {
	int a[10], x = 0;
	while (n) {
		a[x++] = n % 10;
		n /= 10;
	}
	for (int i = 0; i < x / 2; i++)
		if (a[i] != a[x - i - 1])
			return false;
	return true;
}
