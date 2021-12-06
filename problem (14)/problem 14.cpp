#include <iostream>
using namespace std;
int javab(long long int j);
int main() {
	int ans;
	int max = 0;
	for (int i = 500000; i < 1000000; i++) {
		if (javab(i) > max) {
			max = javab(i);
			ans = i;
		}
	}
	cout << ans << endl;
	cout << clock() << endl;
	system("pause");
	return 0;
}
int javab(long long int j) {
	long long int q = j;
	if (j == 1)
		return 0;
	if (j % 2)
		j = 3 * j + 1;
	else
		j /= 2;
	return javab(j) + 1;	
}
