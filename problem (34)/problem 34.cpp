#include <iostream>

using namespace std;

bool h(int n);
int fact(int n);

int main() {
	int sum = 0;
	for (int i = 10; i < 10000000; i++)
		if (h(i))
			sum += i;
	cout << sum << endl << clock() << endl;
	system("pause");
	return 0;
}
bool h(int n) {
	int tmp = n;
	bool d = false;
	int k;
	int a[10] = {};
	for (int i = 0; i < 10; i++) {
		a[i] = n % 10;
		n /= 10;
		if (!(n) && !(d)) {
			k = i + 1;
			d = true;	
		}
	}
	int s = 0;
	for (int i = 0; i < k; i++)
		s += fact(a[i]);
	if (tmp == s)
		return true;
	else
		return false;
}
int fact(int n) {
	if (!n)
		return 1;
	return fact(n - 1) * n;
}	
