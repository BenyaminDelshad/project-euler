#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main() {
	ifstream fin("names.txt");
	char in[110000];
	char input[5500][20];
	fin >> in;
	int counter = 0;
	for(int i = 0; i < strlen(in); i++)
		if(in[i] == '"') {
			int tmp = 0;
			while (in[i + 1] != '"') {
				i++;
				input[counter][tmp++] = in[i];
			}
			counter++;
			i += 2;
		}
	int cc = 0;
	while(strlen(input[cc]))
		cc++;
	for (int i = 1; i < cc ; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (strcmp(input[j], input[j + 1]) > 0) { 
				for (int k = 0; k < 20; k++)
					swap(input[j][k], input[j + 1][k]);
			}
		}
	}
	int i = 0;
	long long int sum = 0;
	while(strlen(input[i])) {
		int tmp = 0;
		for(int j = 0; j < strlen(input[i]); j++)
			tmp += (int)input[i][j] - 64;
		sum += (tmp * (i + 1));
		i++;	
	}
	cout << sum << endl << clock() << endl;
	system("pause");
	return 0;
}
