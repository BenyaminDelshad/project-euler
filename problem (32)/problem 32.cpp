#include <iostream>

using namespace std;

bool tekrari(int n);
bool pandigital(int a, int b);

int main() {
	int sum = 0;
	int tmp;
	for (int i = 1234; i < 9877; i++)
		if (tekrari(i)) {
			bool d = true;
			for (int j = 2; j * j <= i; j++)
				if (!(i % j) && d) {
					if (j < 10)
						tmp = j + 10 * (i / j) + 100000 * i;
					else
						tmp = j + 100 * (i / j) + 100000 * i;
					if (pandigital(tmp, 9)) {	
						sum += i;
						d = false;	
					}
				}
		}
	cout << sum << endl << clock() << endl;	
	system("pause");
	return 0;
}
bool tekrari(int n) {
	int m[4] = {};
	for (int i = 0; i < 4; i++) {
		m[i] = n % 10;
		n /= 10;
	}
	int v = true;
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			if (m[i] == m[j])
				v = false;
	return v;
}			
bool pandigital(int a, int b) {
	int m[9] = {};
	for (int i = 0; i < b; i++) {
		m[i] = a % 10;
		a /= 10;	
	}
	bool s = true;
	for (int i = 0; i < b; i++) {
		if (!(m[i]))
			s = false;
		for (int j = i + 1; j < b; j++)
			if(m[i] == m[j])
				s = false;
	}
	return s;
}
