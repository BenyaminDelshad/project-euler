#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin ("triangle.txt");
	int triangle[100][100] = {};
	for (int i = 0; i < 100;i++)
		for (int j = 0; j <= i; j++)
			fin >> triangle[i][j];
	int javab[100][100] = {};
	for (int i = 0; i < 100; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++)
			sum += triangle[j][0];
		javab[i][0] = sum;
	}
	for (int i = 0; i < 100; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++)
			sum += triangle[j][j];
		javab[i][i] = sum;
	}
	for (int i = 2; i < 100; i++)
		for (int j = 1; j < 99; j++)
			if (javab[i - 1][j - 1] > javab[i - 1][j])
				javab[i][j] = javab[i - 1][j - 1] + triangle[i][j];
			else
				javab[i][j] = javab[i - 1][j] + triangle[i][j];	
	int max = 0;
	for (int i = 0; i < 100; i++)
		if (javab[99][i] > max)
			max = javab[99][i];
	cout << max << endl;		
	system("pause");
	return 0;
}
