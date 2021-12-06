#include <iostream>
using namespace std;

bool is_prime(int n);

int main() {
	long long int k = (long long int) 6008514 * 100000 + 75143;
	for (int i = 2; (long long int) i * i <= k; i++)
		if (!(k % i) && is_prime(i))
			while (!(k % i))
				k /= i;
	cout << k << endl << clock() << endl;		 	
	system("pause");
	return 0;
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
