#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin ("input.txt");
	int adad[20][20];
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 20; j++)
			 fin >> adad[i][j];
	int max = 0;
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 17; j++)
			if (adad[i][j] * adad[i][j + 1] * adad[i][j + 2] * adad[i][j + 3] > max) 		 	
				max = adad[i][j] * adad[i][j + 1] * adad[i][j + 2] * adad[i][j + 3];
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 20; j++)
			if (adad[i][j] * adad[i + 1][j] * adad[i + 2][j] * adad[i + 3][j] > max) 		 	
				max = adad[i][j] * adad[i + 1][j] * adad[i + 2][j] * adad[i + 3][j];
	for (int i = 0; i < 17; i++)
		for (int j = 0; j < 17; j++)
			if (adad[i][j] * adad[i + 1][j + 1] * adad[i + 2][j + 2] * adad[i + 3][j + 3] > max) 		 	
				max = adad[i][j] * adad[i + 1][j + 1] * adad[i + 2][j + 2] * adad[i + 3][j + 3];
	for (int i = 0; i < 17; i++)
		for (int j = 3; j < 20; j++)
			if (adad[i][j] * adad[i + 1][j - 1] * adad[i + 2][j - 2] * adad[i + 3][j - 3] > max) 		 	
				max = adad[i][j] * adad[i + 1][j - 1] * adad[i + 2][j - 2] * adad[i + 3][j - 3];
	cout << max << endl;
	system("pause");
	return 0;
}
