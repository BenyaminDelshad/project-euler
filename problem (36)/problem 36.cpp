#include <iostream>

using namespace std;

bool aine(int n);

int main() {
	int sum = 0;
	for (int i = 1; i < 1000000; i++)
		if (aine(i))
			sum += i;
	cout << sum << endl << clock() << endl;
	
	system("pause");
	return 0;
}
bool aine(int n) {
	int tmp = n;
	int a[6] = {};
	bool s1 = true;
	int k;
	bool d = false;
	for (int i = 0; i < 6; i++) {
		a[i] = n % 10;
		n /= 10;
		if (!(n) && !(d)) {
			k = i + 1;
			d = true;	
		}
	}
	for (int i = 0; i < k / 2; i++)
		if (a[i] != a[k - i - 1])
			s1 = false;
	n = tmp;
	int b[20] = {};
	bool s2 = true;
	int f = 0;
	while(n) {
		if(n % 2)
			b[f] = 1;
		else
			b[f] = 0;
		n /= 2;
		f++;	
	}
	for (int i = 0; i < f / 2; i++)
		if (b[i] != b[f - i - 1])
			s2 = false;
	return (s1 && s2);
}
