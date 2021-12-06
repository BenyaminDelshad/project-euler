#include <iostream>

using namespace std;

bool dori(int n);
bool is_prime(int n);

int main() {
	int counter = 0;
	for (int i = 2; i < 1000000; i++)
		if (dori(i))
			counter++;
	cout << counter << endl << clock() << endl;
	system("pause"); 
	return 0;
}
bool dori(int n) {
	int a[6] = {};
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
	for (int i = 0; i < k; i++) {
		int u = 0;
		for (int j = i; j < i + k; j++)
			u = 10 * u + a[j % k];
		if (!(is_prime(u)))
			return false;	
	}
	return true;
}
bool is_prime(int n) {
	if (n == 2)
		return true;
	if (!(n % 2))
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (!(n % i))
			return false;	
	return true;				
}
