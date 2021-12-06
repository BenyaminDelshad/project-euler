#include <iostream>
#include <algorithm>
#include <fstream>
#include <map>
#include <ctime>
using namespace std;

ifstream fin("roman.txt");
string s;
map<char, int>m;
int ans, I, V, X, L, C, D, M;

void f(int k) {
	int a[4];
	for(int i = 3; i >= 0; i--){
		a[i] = k % 10;
		k /= 10;
	}
	if(a[0]) M += a[0];
	if(a[1] == 9){
		M++;
		C++;
		a[1] = 0;
	}
	if(a[1] >= 4){
		D++;
		a[1] -= 5;
	}
	C += abs(a[1]);
	if(a[2] == 9){
		C++;
		X++;
		a[2] = 0;
	}
	if(a[2] >= 4){
		L++;
		a[2] -= 5;
	}
	X += abs(a[2]);
	if(a[3] == 9){
		X++;
		I++;
		a[3] = 0;
	}
	if(a[3] >= 4){
		V++;
		a[3] -= 5;
	}
	I += abs(a[3]);
	return;
}

int main() {
	m['I'] = 1;
	m['V'] = 5;
	m['X'] = 10;
	m['L'] = 50;
	m['C'] = 100;
	m['D'] = 500;
	m['M'] = 1000;
	for(int i = 0; i < 1000; ++i) {
		fin >> s;	
		int num = 0;
		ans += s.size();
		for(int j = 0; j < s.size(); ++j) {
			if(j < s.size() - 1 && m[char(s[j])] < m[char(s[j + 1])]) {
				num -= m[char(s[j])];
				continue;
			}	
			num += m[s[j]];
		}
		f(num);		
	}
	cout << ans - (I + V + X + L + C + D + M) << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
