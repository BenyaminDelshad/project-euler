#include <iostream>

using namespace std;

int main() {
	int a = 0;
	int b = 0;
	int c = 1001;
	bool d = true;
	while (d) {
		c--;
		for (int i = 1; i <= (1000 - c) / 2; i++) {
			a = i;
			b = 1000 - c - a;
			if (a * a + b * b == c * c) {
				d = false;
				cout << a * b * c << endl; 
			}
		}
	}
	system("pause");
	return 0;
}
