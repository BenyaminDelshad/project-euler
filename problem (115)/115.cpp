#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;
ll b[1000];

int main() {
	for(int i = 0; i < 50; ++i)
		b[i] = 1;
	for(int i = 50; ; ++i) {
		b[i] += b[i - 1];
		for(int j = i - 51; j >= 0; --j)
			b[i] += b[j];
		b[i]++;	
		if(b[i] > 1000 * 1000) {
			cout << i << endl;
			break;
		}
	}
	system("pause");
	return 0;
}
