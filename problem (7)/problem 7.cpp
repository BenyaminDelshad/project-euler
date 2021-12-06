#include <iostream>

using namespace std;

bool is_prime (int i);

int main() {
	int counter = 0;
	int num = 1;
	while(counter < 10001) {		
		num++;
		if (is_prime(num))
			counter++;
	}
	cout << num << endl << clock() << endl;
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
