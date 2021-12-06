#include <iostream>

using namespace std;

int fact(int a);

int main() {
	int a[10] = {};
	bool b[10] = {};
	int ja = 0;
	for (int i = 0; i < 10; i++) {
		bool aa = true;
		int j = 0;
		while (aa) {
			if (!(b[j]))
				if (ja + fact(9 - i) < 1000000)
					ja += fact(9 - i);
				else {
					a[i] = j;
					b[j] = true;
					aa = false;
				}
			j++;
		}
	}
	for (int i = 0; i < 10; i++)
		cout << a[i];
	cout << endl << clock() << endl;
	system("pause");
	return 0;
}
int fact(int a) {
	int c = 1;
	for (int i = a; i > 0; i--)
		c *= i;
	return c;		
}
