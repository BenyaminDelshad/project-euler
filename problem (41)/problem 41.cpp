#include <iostream>
#include <algorithm>

using namespace std;

bool is_prime(int n);
int next(int n, int a);
//next_permutation(a, a + n);
int main() {
	
	int a = 1234567;
	int max = 0;
	for (int i = 0; i < 5039; i++) {
		if (is_prime(a))
			max = a;
		a = next(a, 7);	
	}
	if (is_prime(a))
		max = a;
	
	cout << max << endl << clock() << endl;	
	system("pause");
	return 0;
}
bool is_prime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (!(n % i))
			return false;
	return n > 1;
}				
int next(int n, int a) {
	int adad[10] = {}, m = n;
	for (int i = a - 1; i >= 0; i--) {
		adad[i] = n % 10;
		n /= 10;
	}
	int i = a - 1;
	while(i >= 0 && adad[i] < adad[i - 1])
		i--;
	if (!i)
		return m;
	reverse(adad + i, adad + a);
	int cnt = i;
	while (cnt < a && adad[i - 1] > adad[cnt])
		cnt++;
	swap(adad[i - 1], adad[cnt]);
	int temp = 0;
	for (int i = 0; i < a; i++)
		temp = temp * 10 + adad[i];
	return temp;
}
