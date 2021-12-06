#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int a[1000 * 1000 * 100 + 10];
vector <int>ans;
int main() {
	for(int i = 1; i < 1000 * 1000 * 10 * 5 + 1; i++)
		for(int j = i; j <= 1000 * 1000 * 100; j += i)
			a[j]++;
	int f = 0;
	for (int i = 1; i <= 1000 * 1000 * 100; i++)
		if(a[i] == 2) ans.push_back(i);
	for(int i = 0; i < ans.size(); i++)	
		for(int j = i; j < ans.size() && (long long)ans[i] * ans[j] <= 1000 * 1000 * 100; j++)
			f++;
	cout << f << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
