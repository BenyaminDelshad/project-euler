#include <iostream>

using namespace std;

int main() {
	int sum = 0;
	for (int i = 1; i < 1002; i+= 2)
		sum += (i * i) + (i * i - (i - 1));
	for (int i = 2; i < 1002; i+= 2)
		sum += (i * i + 1) + (i * i + 1 - i);
	sum--;	
	cout << sum << endl << clock << endl;			
	system("pause");
	return 0;
}
