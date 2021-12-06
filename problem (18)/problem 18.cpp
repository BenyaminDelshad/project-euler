#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin ("triangle.txt");
	int triangle[15][15] = {};
	for (int i = 0; i < 15;i++)
		for (int j = 0; j <= i; j++)
			fin >> triangle[i][j];
	int javab[15][15] = {};
	for (int i = 0; i < 15; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++)
			sum += triangle[j][0];
		javab[i][0] = sum;
	}
	for (int i = 0; i < 15; i++) {
		int sum = 0;
		for (int j = 0; j <= i; j++)
			sum += triangle[j][j];
		javab[i][i] = sum;
	}
	for (int i = 2; i < 15; i++)
		for (int j = 1; j < 14; j++)
			if (javab[i - 1][j - 1] > javab[i - 1][j])
				javab[i][j] = javab[i - 1][j - 1] + triangle[i][j];
			else
				javab[i][j] = javab[i - 1][j] + triangle[i][j];	
	int max = 0;
	for (int i = 0; i < 15; i++)
		if (javab[14][i] > max)
			max = javab[14][i];
	cout << max << endl;		
	system("pause");
	return 0;
}
