#include <iostream>

using namespace std;

int f(int n);
int tedad(int n);
int pow(int a, int b);

int main() {
	int max = 0;
	for (int i = 1; i < 10000; i++)
		if(f(i) > max)
			max = f(i);
	cout << max << endl << clock() << endl;
	system("pause");
	return 0;	
}
int f(int n) {
	bool d = false;
	int a[10] = {};
	int counter = 0;
	for (int i = 1; i < 10; i++)
		a[i] = n * i;
	int t[10] = {};
	int tmp = 0;
	for (int i = 1; i < 10; i++) {
		t[i] = tedad(a[i]);
		counter += t[i];
		if (counter == 9) {
			d = true;
			tmp = i;
		}
	}
	if (!(tmp))
		return 0;
	int khoruji = 0;
	for (int i = 1; i <= tmp; i++)
		khoruji = khoruji * pow(10, t[i]) + a[i];
	int tmp2 = khoruji;
	int tmp3;
	bool x[10] = {};
	for (int i = 0; i < 10; i++) {
		tmp3 = tmp2 % 10;
		x[tmp3] = true;
		tmp2 /= 10;	
	}
	for (int i = 1; i <= 10; i++)
		if (!(x[i]))
			return 0;
	return khoruji;		
}
int tedad(int n) {
	int counter = 0;
	while(n) {
		counter++;
		n /= 10;
	}
	return counter;
}
int pow(int a, int b) {
	int tmp = 1;
	for (int i = 0; i < b; i++)
		tmp *= a;
	return tmp;		
}
