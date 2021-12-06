#include <iostream>

using namespace std;

int tedad_m(int n);
bool is_prime(int n);

int main() {
	int maqsum_elayh = 0;
	int n = 1;
	while (maqsum_elayh <= 500) {
	n++;
	maqsum_elayh = tedad_m(n * (n + 1) / 2);
	}
	cout << n * (n + 1) / 2 << endl;
	system("pause");
	return 0;
}
int tedad_m(int n) {
	int s , p = 1;
	for(int i = 2; i * i <= n; i++)
		if (!(n % i)) {
			s = 0;
			while (!(n % i)) {
				n /= i;
				s++;
			}
			p *= (s + 1);
		}
	if(n == 1)
		return p;
	else
		return 2 * p;
}
