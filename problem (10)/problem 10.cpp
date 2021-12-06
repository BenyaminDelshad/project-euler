#include <iostream>

using namespace std;

bool is_prime(int n);
int main() {
	long long int sum = 0;
	int num = 1;
	while(num < 2000000) {		
		num++;
		if (is_prime(num))
			sum+= num;
	}
	cout << sum << endl << clock() << endl;
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
