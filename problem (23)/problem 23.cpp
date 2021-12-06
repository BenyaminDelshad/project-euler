#include <iostream>

using namespace std;

int main() {
	bool adad[28124] = {};
	for (int i = 1; i < 28124; i++) {
		int sum = 0;
		for (int j = 1; j < i; j++)
			if (!(i % j))
				sum += j;
		if (sum > i)
			adad[i] = true;
	}
	
	int s = 0;
	for(int i = 0; i < 28124; i++) {
		bool b = true;
		for (int j = 0; j <= i / 2; j++)
			if ((adad[i - j]) && (adad[j]))
				b = false;
		if (b)
			s += i;
	}
	cout << s << endl << clock() << endl; 
	system("pause");
	return 0;
}
