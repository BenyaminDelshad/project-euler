#include <iostream>
#include <algorithm>
using namespace std;

bool Soudi(int n) {
	int num[10] = {};
	int s = 0;
	int tmp = n;
	while(tmp){
		num[s++] = tmp % 10;
		tmp /= 10;
	}
	for (int i = s - 2; i >= 0; i--)
		if(num[i] < num[i + 1])
			return false;
	return true;		
}

bool Nozuli(int n) {
	int num[10] = {};
	int s = 0;
	int tmp = n;
	while(tmp){
		num[s++] = tmp % 10;
		tmp /= 10;
	}
	for (int i = s - 2; i >= 0; i--)
		if(num[i] > num[i + 1])
			return false;
	return true;
}

int main() {
	int ans = 0;
	int kol = 0;
	for (int i = 1; ; i++){
		if(!Soudi(i) && !Nozuli(i))
			ans++;
		kol++;
		if(ans * 100 == 99 * kol){
			cout << i << endl;
			break;
		}
	}
	cout << "Time " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
