//In the name of God
#include <iostream>
#include <vector>
using namespace std;

int main() {
	static bool f[100000000];
	int d = 1000 * 1000 * 1000;
	vector <int> v;
	for (int i = 1; (i * (3 * i - 1)) / 2 < 1000 * 1000 * 10 * 5; ++i) {
		v.push_back((i * (3 * i - 1)) / 2);
		f[(i * (3 * i - 1)) / 2] = true;
	}
	for (int i = 0; i < v.size(); ++i)
		for (int j = i + 1; j < v.size(); ++j)
			if (f[v[i] + v[j]] && f[abs(v[i] - v[j])])
				if (abs(v[i] - v[j]) < d)
					d = abs(v[i] - v[j]);
	cout << d << endl << clock() << endl;
	system("pause");
	return 0;
}
