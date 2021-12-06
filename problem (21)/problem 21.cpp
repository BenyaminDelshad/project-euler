#include <iostream>
	
using namespace std;

int d(int i);

int main() {
	int sum = 0;
	for(int i = 2; i < 10000; i++) {
		if ((i == d(d(i))) && (i != d(i)))
			sum += d(i);
	}
	cout << sum << endl;
	system("pause");
	return 0;
}
int d(int i) {
	int sum = 0;
	for(int j = 1; j < i; j++)
		if(!(i % j))
			sum += j;
	return sum;		 
}
