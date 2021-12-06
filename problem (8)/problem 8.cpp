#include <iostream>
#include <fstream>

using namespace std;

int b[1000];

int check_max(int i);

int main() {
	ifstream fin ("input.txt");
	char a[20][51];
	for (int i = 0; i < 20; i++) {	
		fin >> a[i];
		}
	for (int i = 0; i < 20; i++)
		for (int j = 0; j < 50; j++)
			b[50 * i + j] = a[i][j] - '0';
	int max = 0;
	for (int i = 0; i < 996; i++)
		if (check_max(i) > max)
			max = check_max(i);
	cout <<  max << endl << clock() << endl;
	system("pause");
	return 0;
}
int check_max(int i) {
	return b[i] * b[i + 1] * b[i + 2] * b[i + 3] * b[i + 4];	
}
