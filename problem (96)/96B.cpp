#include <iostream>
#include <algorithm>
#include <fstream>
using namespace std;

ifstream fin("sudoku.txt");
int arr[10][10];
int ans, u;
bool mark[10][10];

void BT(int x, int y) {
	if(x == 8 && y == 8) {
		bool mark2[10];
		fill(mark2, mark2 + 10, false);
		for(int h = 0; h < 9; ++h) {
			mark2[arr[x][h]] = true;	
			mark2[arr[h][y]] = true;
		}
		int xx = ((x) / 3) * 3;
		int yy = ((y) / 3) * 3;
		for(int h = xx; h < xx + 3; ++h)
			for(int g = yy; g < yy + 3; ++g)
				mark2[arr[h][g]] = true;
		int counter = 0;
		for(int h = 0; h <= 9; ++h)
			if(!mark2[h])
				counter++;
		if(counter)
			ans += 100 * arr[0][0] + 10 * arr[0][1] + arr[0][2];
		return; 
	}
	if(!mark[x][y]) {
		if(y < 8) BT(x,y + 1);
		else BT(x + 1, 0);
		return;
	}
	bool mark2[10];
	fill(mark2, mark2 + 10, false);
	for(int h = 0; h < 9; ++h) {
		mark2[arr[x][h]] = true;	
		mark2[arr[h][y]] = true;
	}
	int xx = ((x) / 3) * 3;
	int yy = ((y) / 3) * 3;
	for(int h = xx; h < xx + 3; ++h)
		for(int g = yy; g < yy + 3; ++g)
			mark2[arr[h][g]] = true;
	for(int i = 1; i < 10; ++i) {
		if(mark2[i]) continue;
		arr[x][y] = i;
		if(y < 8)
			BT(x, y + 1);
		else 
			BT(x + 1, 0);
		arr[x][y] = 0;
	}		
}

int main() {
	for(int i = 0; i < 50; ++i) {
		int tmp;
		char c;
		string s;
		int zero = 0;
		fin >> s >> tmp;
		for(int j = 0; j < 9; ++j)
			for(int k = 0;k < 9; ++k) {
				fin >> c;
				arr[j][k] = int(c - '0');
				if(!arr[j][k]) zero++;
			}
		for(int j = 0; j < 9; ++j)
			for(int k = 0; k < 9; ++k)
				if(arr[j][k] == 0) 
					mark[j][k] = true;
				else
					mark[j][k] = false;	
		BT(0 ,0);
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
