#include <iostream>

using namespace std;

void f(int n, int &k);
int g(int n, int max);

int a[8] = {1, 2, 5, 10, 20, 50, 100 ,200};
	
int main() {
	int k = 0;
	f(200, k);
	cout << k << endl << clock() << endl;
	system("pause");
	return 0;
}
void f(int n, int &k) {
	k = 0;
	for(int i = 0; i < 8; i++)
		k += g(n, i);
}
int g(int n, int max) {
	if (a[max] > n)
		return 0;	
	if (a[max] == n)
		return 1;
	int s = 0;
	for (int i = 0; i <= max; i++) 
		s += g(n - a[max], i); 
	return s;
}
