#include <iostream>
#include <algorithm>
using namespace std;

int a[1500];

int f(int x, int y){
	for(int i = 0; i < 1500; i++)
		a[i] = 0;
	a[0] = 1;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < 1001; j++)
			a[j] *= x;
		for(int j = 0; j < 1001; j++)
			if(a[j] > 9){
				a[j + 1] += a[j] / 10;
				a[j] %= 10;
			}
	}
	int ans = 0;
	for(int i = 0; i < 1500; i++)
		ans += a[i];
	return ans;		
}

int main(){
	int Max = 0;
	for(int i = 1; i < 100; i++)
		for(int j = 1; j < 100; j++)
			if(Max < f(i, j))
				Max = f(i, j);
	cout << Max << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
