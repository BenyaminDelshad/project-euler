#include <iostream>

using namespace std;

int f(int n);

int main() {
	int max = 0;
	int andis;
	for (int i = 3; i <= 1000; i++)
		if (f(i) > max) {
			max = f(i);
			andis = i;
		}
	cout << andis << endl << clock() << endl;
	system("pause");
	return 0;
}
int f(int n) {
	int counter = 0;
	for (int i = 1; i <= n / 3; i++)
		for (int j = i; i + j <= 2 * n / 3; j++) {
			int k = n - i - j;
			if (i * i + j * j == k * k)
				counter++;	
		}
	return counter;
}
