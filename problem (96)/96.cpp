#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("sudoku.txt");
int arr[10][10];
int ans;

int main() {
	for(int i = 0; i < 50; ++i) {
		int tmp;
		char c;
		string s;
		int zero = 0;
		fin >> s >> tmp;
		for(int j = 1; j < 10; ++j)
			for(int k = 1;k < 10; ++k) {
				fin >> c;
				arr[j][k] = int(c - '0');
				if(!arr[j][k]) zero++;
			}
		for(int j = 0; j < zero; ++j) {
			bool flag = false;
			for(int k = 1; k < 10; ++k) {
				if(flag) break;
				for(int t = 1; t < 10; ++t) {
					if(flag) break;
					if(arr[k][t]) continue;
					bool mark[10];
					fill(mark, mark + 10, false);
					for(int h = 1; h < 10; ++h) {
						mark[arr[k][h]] = true;	
						mark[arr[h][t]] = true;
					}
					int x = ((k-1) / 3) * 3 + 1;
					int y = ((t-1) / 3) * 3 + 1;
					for(int h = x; h < x + 3; ++h)
						for(int g = y; g < y + 3; ++g)
							mark[arr[h][g]] = true;
					int counter = 0;
					int r;
					for(int h = 1; h < 10; ++h)
						if(!mark[h]) {
							counter++;
						 	r = h;
						}
					if(counter > 1) continue;
					arr[k][t] = r;
					flag = true;  
				}	
			}
		}
		ans += (arr[1][1] * 100 + arr[1][2] * 10 + arr[1][3]);
		cerr << arr[1][1] * 100 + arr[1][2] * 10 + arr[1][3] << endl;
		if(i == 1) {
			for(int j = 1; j < 10; ++j) {
				for(int k = 1; k < 10; ++k)
					cerr << arr[j][k] << ' ';
				cerr << endl;
			}
		}
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
