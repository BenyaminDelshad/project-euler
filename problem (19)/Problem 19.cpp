#include <iostream>

using namespace std;

int main() {
	bool kabise[100] = {};
	for (int i = 1901; i < 2001; i++)
		if (!(i % 4))
			kabise[i - 1901] = true;
	int mounth[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	int sal[100][367] = {};
	sal[0][1] = 1;
	for (int i = 2; i < 366; i++)
		sal[0][i] = (sal[0][i - 1] + 1) % 7;
	for (int i = 1 ;i < 100; i++) {
		if (kabise[i - 1])
			sal[i][1] = (sal[i - 1][366] + 1) % 7;
		else
			sal[i][1] = (sal[i - 1][365] + 1) % 7;	
		for (int j = 2; j < 366; j++)
			sal[i][j] = (sal[i][j - 1] + 1) % 7;
		if (kabise[i])
			sal[i][366] = (sal[i][365] + 1) % 7;	
	}
	int counter = 0;
	for (int i = 0; i < 100; i++) {
		if (sal[i][1] == 6)
			counter++;
		if (sal[i][32] == 6)
			counter++;
		int m = mounth[1] + mounth[2];
		if (kabise[i])
			for (int j = 3; j < 13; j++) {
				if (sal[i][m + 1 + 1] == 6)
					counter++;
				m += mounth[j];
			}
		else
			for (int j = 3; j < 13; j++) {
				if (sal[i][m + 1] == 6) 
					counter++;
				m += mounth[j];
			}
					
	}
	cout << counter << endl << clock() << endl;
	system("pause");
	return 0;
}
