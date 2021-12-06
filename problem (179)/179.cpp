#include <iostream>
#include <algorithm>
using namespace std;

int a[1000 * 1000 * 10 + 10];

int main() {
	for(int i = 1; i < 1000 * 1000 * 5 + 1; i++)
		for(int j = i; j <= 1000 * 1000 * 10; j += i)
			a[j]++;
	int ans = 0;
	for (int i = 1; i < 1000 * 1000 * 10; i++)
		if(a[i] == a[i + 1]) ans++;
	cout << ans << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
