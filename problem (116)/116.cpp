#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

ll red[60], blue[60], green[60];

int main() {
	red[0] = red[1] = blue[0] = blue[1] = blue[2] = blue[3] = green[0] = green[1] = green[2] = 1;
	for(int i = 2; i < 51; ++i)
		red[i] = red[i - 1] + red[i - 2];
	for(int i = 3; i < 51; ++i)
		green[i] = green[i - 1] + green[i - 3];
	for(int i = 4; i < 51; ++i)
		blue[i] = blue[i - 1] + blue[i - 4];
	cout << red[50] + green[50] + blue[50]  - 3 << endl;
	system("pause");
	return 0;
}
