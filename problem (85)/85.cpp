#include <iostream>
#include <algorithm>
using namespace std;

long long f(int n, int m){
	return (long long) n * (n + 1) * m * (m + 1) / 4;
}

int main() {
	long long r, h= 10000000, ans;
	for(int i = 1; i < 1000; i++){
		for(int j = i; j < 1000; j++){
			r = (long long) f(i, j);
			if(r > 2000000){
				if(r - 2000000 < h){
					h = r - 2000000;
					ans = i * j;	
				}
			}
			else{
				if(2000000 - r < h){
					h = 2000000 - r;
					ans = i * j;
				}
			}
		}
	}
	cout << ans << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
