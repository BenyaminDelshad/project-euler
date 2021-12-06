#include <iostream>
#include <fstream>

using namespace std;

int main() {
	ifstream fin ("input.txt");
	char in[100][51];
	int v[100][50];
	for (int i = 0; i < 100; i++)
		fin >> in[i];
	for(int i = 0; i < 100; i++)
		for(int j = 0; j < 50; j++)
			v[i][49 - j] = in[i][j] - '0';
	int sum[53] = {};
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 50; j++)
			sum[j] += v[i][j];
	for (int i = 0; i < 53; i++)
		if (sum[i] > 9) {
			sum[i + 1] += sum[i] / 10;
			sum[i] = sum[i] % 10;	
		}
	int e = 52;
	while(!(sum[e]))
		e--;
	for (int i = e; i > e - 10; i--)
		cout << sum[i];
	cout << endl;		
	system("pause");
	return 0;
}
