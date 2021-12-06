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
	for (int i = 0; i < 80; i++)
		javab[i][0] = b[i][0];
	for (int i = 1; i < 80; i++)
		for (int j = 0; j < 80; j++){
			int mn = 1000 * 1000 * 100;
			for(int k = 0; k <= j; k++){
				int sum = 0;
				for(int t = k; t <= j; t++)
					sum += b[t][i];
				if (mn > sum + javab[k][i - 1])
					mn = sum + javab[k][i - 1];
			}
			for(int k = j + 1; k < 80; k++){
				int sum = 0;
				for(int t = k; t >= j; t--)
					sum += b[t][i];
				if (mn > sum + javab[k][i - 1])
					mn = sum + javab[k][i - 1];
			}
			javab[j][i] = mn;	
		}
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 8; j++)
			cout << b[i][j] << "  ";
		cout << endl;		
	}
	long long int mn = (long long)1000 * 1000 * 1000 * 1000 * 1000 * 1000;
	for(int i = 0; i < 80; i++)
		if(b[i][79] < mn)
			mn = b[i][79];
	cout << mn << endl << clock() << endl;		
	system("pause");
	return 0;
}
