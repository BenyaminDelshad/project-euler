#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
ll b[60];

int main() {
	b[0] = b[1] = b[2] = 1;
	for(int i = 3; i < 51; ++i) {
		b[i] += b[i - 1];
		for(int j = i - 4; j >= 0; --j)
			b[i] += b[j];
		b[i]++;	
	}
	cout << b[50] << endl;
	system("pause");
	return 0;
}
