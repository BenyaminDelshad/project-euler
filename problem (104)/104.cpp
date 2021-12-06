#include <iostream>
#include <algorithm>
using namespace std;

int f1[75000], f2[75000], f3[75000];
bool m1[10];
int main() {
	f1[0] = 1, f2[0] = 1;
	for(int i = 3; ; ++i) {
		if(i % 100 == 0) cerr << i << endl;
		bool flag = false;
		fill(f3, f3 + 75000, 0);
		fill(m1, m1 + 10, false);
		for(int j = 0; j < 75000; ++j)
			f3[j] = f1[j] + f2[j];
		for(int j = 0; j < 74999; ++j) {
			f3[j + 1] += f3[j] / 10;
			f3[j] %= 10;
		}
		for(int j = 0; j < 74999; ++j) {
			f1[j] = f2[j];
			f2[j] = f3[j];
		} 
		// check f2:
		for(int j = 0; j < 9; ++j)
			m1[f2[j]] = true;
		for(int j = 1; j < 10; ++j)
			if(!m1[j]) flag = true;
		fill (m1, m1 + 10, false);
		int t = 74999;
		while(f2[t] == 0) t--;
		for(int j = t; j > t - 9; j--)
			m1[f2[j]] = true;
		for(int j = 1; j < 10; ++j)
			if(!m1[j]) flag = true;
		if(flag) continue;
		cout << i << endl;
		break;
	}	
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
