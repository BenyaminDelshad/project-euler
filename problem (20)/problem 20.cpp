#include <iostream>

using namespace std;

int main() {
	int adad[201] = {};
	int javab[201] = {};
	adad[4] = 8 ,adad[5] = 8 ,adad[6] = 2 ,adad[7] = 6 , adad[8] = 3;
	for (int i = 1; i < 10; i++)
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k < 200; k++) {
				javab[k] += adad[k] * j;
				javab[k + 1] += adad[k] * i;
			}
			for (int l = 0; l < 200; l++)
				if(javab[l] > 9) {
					javab[l + 1] += javab[l] / 10;
					javab[l] = javab[l] % 10;		
				}
			for (int g = 0; g < 200; g++) {
				adad[g] = javab[g];
				javab[g] = 0; 		
			}
		}
	int sum = 0;
	for (int i = 0; i < 200; i++)
		sum += adad[i];
	cout << sum << endl;
	system("pause");
	return 0;
}
