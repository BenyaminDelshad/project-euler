#include <iostream>

using namespace std;

int kmm(int n);
bool is_prime(int i);

int main() {
	int n = 20;
	cout << kmm(n) << endl << clock() << endl;
	system("pause");
	return 0;
}
int kmm(int n) {
	int tavan[21] = {};
	for (int i = 2; i < 21; i++)
		if(is_prime(i))
			for (int j = 2; j < 21; j++) {
				int counter = 0;
				int k = j;
				while (!(k % i)) {
				k /= i;
				counter++;
				}
				if (counter > tavan[i])
					tavan[i] = counter;
			}
	int javab = 1;
	for (int i = 2; i < 21; i++)
		if(is_prime(i))
			for(int j = 0; j < tavan[i]; j++)
				javab *= i;
	return javab;					
}
bool is_prime(int i) {
	if (i == 2)
		return true;
	if (!(i % 2))
		return false;
	for(int j = 3; j * j <= i; j += 2)
		if (!(i % j))
			return false;
	return true;
}
