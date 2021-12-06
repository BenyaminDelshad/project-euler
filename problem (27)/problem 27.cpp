#include <iostream>

using namespace std;

bool is_prime (int n);

int main() {
	int aa = 0;
	int bb = 0;
	int max = 0;
	for (int i = -1000; i < 1001; i++)
		for (int j = -1000; j < 1001; j++) {
			bool a = true;
			int counter = 0;
			while(a)
				if (is_prime(counter * counter + i * counter + j))
					counter++;
				else
					a = false;
			if (counter > max) {
				max = counter;
				aa = i;
				bb = j;
			}
		}
	cout << aa * bb << endl << clock() << endl;
	system("pause");
	return 0;
}
bool is_prime(int n) {
	if (n < 0)
		return false;
	if (n == 1 || n == 0)
		return false;
	if (n == 2)
		return true;
	if (!(n % 2))
		return false;
	for (int i = 3; i * i  < n; i += 2)
		if (!(n % i))
			return false;
	return true;
}				
