#include <iostream>

using namespace std;

int main() {
	int adad[308] = {};
	int javab[308] = {};
	adad[0] = 1;
	for (int j = 0;j < 1000; j++) { 
		for(int i = 0; i < 308; i++)
			javab[i] = adad[i] * 2;
		for (int i = 0; i < 308; i++)
			if (javab[i] > 9) {
				javab[i + 1] += javab[i] / 10;
				javab[i] = javab[i] % 10;	
			}	
		for (int i = 0; i < 308; i++) {
			adad[i] = javab[i];
			javab[i] = 0;
		}	
	}
	int sum = 0;
	for (int i = 0; i < 308; i++)
		sum += adad[i];
	cout << sum << endl;	
	system("pause");
	return 0;
}
