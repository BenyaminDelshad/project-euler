#include <iostream>

using namespace std;

bool is_prime(int n);
bool rlprime(int n);

int main() {
	int i = 11;
	int j = 10;
	int sum = 0;
	while (i) {
		j++;
		if (is_prime(j))
			if (rlprime(j)) {
				i--;
				sum += j;
			}
	}
	cout << sum << endl << clock() << endl;
	system("pause");
	return 0;
}
bool is_prime(int n) {
	if (!(n) || n == 1)
		return false;
	if (n == 2)
		return true;
	if (!(n % 2))
		return false;
	for (int i = 3; i * i <= n; i += 2)
		if (!(n % i))
			return false;
	return true;					
}
bool rlprime(int n) {
	int a[10] = {};
	int k;
	bool d = false;
	for (int i = 0; i < 10; i++) {
		a[i] = n % 10;
		n /= 10;
		if (!(n) && !(d)) {
			k = i + 1;
			d = true;	
		}
	}	
	for (int i = 0; i < k; i++) {
		int tmp = 0;
		for (int j = k - 1; j >= i; j--)
			tmp = 10 * tmp + a[j];
		if (!(is_prime(tmp)))
			return false;
	}
	for (int i = 0; i < k; i++) {
		int tmp = 0;
		for (int j = i; j >= 0; j--)
			tmp = 10 * tmp + a[j];
		if (!(is_prime(tmp)))
			return false;
	}
	return true;
}
