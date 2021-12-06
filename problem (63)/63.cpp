#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
int a[50];
int f(int x, int y){
	for(int i = 0; i < 30; i++)
		a[i] = 0;
	a[0] = 1;
	for(int i = 0; i < y; i++){
		for(int j = 0; j < 25; j++)
			a[j] *= x;
		for(int j = 0; j < 25; j++)
			if(a[j] > 9){
				a[j + 1] += a[j] / 10;
				a[j] %= 10;
			}
	}
	int ans = 29;
	for(ans; !a[ans] ; ans--);
	return (ans + 1 == y);		
}
int main(){
	int ans = 0;
	for(int i = 1; i < 10; i++)
		for(int j = 1; j < 24; j++)
			if(f(i, j))
				ans++;
	cout << ans << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
