#include <iostream>

using namespace std;

bool Surprisingly(int n);
int pow(int a, int b);

int main() {
	int sum = 0;
	for(int i = 2; i < 1000000; i++)
		if (Surprisingly(i))
			sum += i;
	cout << sum << endl << clock() << endl;
	system("pause");
	return 0;
}
bool Surprisingly(int n) {
	int a[6] = {};
	int g = n;
	for (int i = 0; i < 6; i++) {
		a[i] = g % 10;
		g /= 10;
	}
	for (int i = 0; i < 6; i++)
		g += pow(a[i], 5);
	if (g == n)
		return true;
	return false;
}
int pow(int a, int b) {
	int f = 1;
	for (int i = 0; i < b; i++)
		f *= a;
	return f;		
}
