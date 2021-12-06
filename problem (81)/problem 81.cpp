#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin("matrix.txt");
	string a;
	int b[100][100] = {};
	int javab[100][100] ={};
	for(int i = 0; i < 80; i++){
		fin >> a;
		int tmp = 0;
		int j = 0;
		while (j < 80){
			while(a[tmp] != ',' && tmp < a.size()){
				b[i][j] = 10 * b[i][j] + (a[tmp] - '0');
				tmp++;
			}
			tmp++;	
			j++;
		}
	}
	int sum1 = 0;
	int sum2 = 0;
	for (int i = 0; i < 80; i++){
		sum1 += b[0][i];
		javab[0][i] = sum1;
		sum2 += b[i][0];
		javab[i][0] = sum2;
	}
	for (int i = 1; i < 80; i++)
		for (int j = 1; j < 80; j++)
			if(javab[i - 1][j] < javab[i][j - 1])
				javab[i][j] = javab[i - 1][j] + b[i][j];
			else
				javab[i][j] = javab[i][j - 1] + b[i][j];
	cout << javab[79][79] << endl << clock() << endl;
	system("pause");
	return 0;
}
