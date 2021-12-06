#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

bool mosalasi(int a);

int main() {
	ifstream fin("words.txt");
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
	int i = 0;
	int cnt = 0;
	while(strlen(input[i])) {
		int tmp = 0;
		for(int j = 0; j < strlen(input[i]); j++)
			tmp += (int)input[i][j] - 64;
		if (mosalasi(tmp))
			cnt++;
		i++;	
	}		
	cout << cnt << endl << clock() << endl;
	system("pause");
	return 0;
}
bool mosalasi(int a) {
	int temp = 0;
	int i = 1;
	while(temp < a){
		temp += i;
		i++;
	}	
	return(temp == a);
}
