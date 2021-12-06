#include <iostream>
using namespace std;
int sum_of_digits(int m);
void my_reverse(int n[], int d[]);
void my_sum(int n[], int d[], int i);
void to_digits(int a[]);
int main() {
	cout << sum_of_digits(100) << '\n' << clock() << '\n';
	system("pause");
	return 0;
}
int sum_of_digits(int m) {
	int n[1000] = {1}, d[1000] = {};
	for (int i = (m - 1) / 3; i >= 1 ; i--) {
		my_reverse(n, d);
		my_sum(n, d, 1);
		my_reverse(n, d);
		to_digits(n);
		my_sum(n, d, 2 * i);
		to_digits(n);
		my_reverse(n, d);
		my_sum(n, d, 1);
		to_digits(n);
	}
	my_reverse(n, d);
	my_sum(n, d, 2);
	to_digits(n);
	int cnt = 999, sum = 0;
	while (!n[cnt])
		cnt--;
	for (int i = 0; i <= cnt; i++)
		sum += n[i];
	return sum;
}
void my_reverse(int n[], int d[]) {
	for (int i = 0; i < 1000; i++)
		swap(n[i], d[i]);
}
void my_sum(int n[], int d[], int i) {
	for (int j = 0; j < 1000; j++)
		n[j] += i * d[j];
}
void to_digits(int a[]) {
	for (int i = 0; i < 999; i++) {
		a[i + 1] += a[i] / 10;
		a[i] %= 10;
	}
}
