#include <iostream>

using namespace std;

bool javab(int i, int j);
int gcd(int n, int m);
	
int sorat = 1;

int main() {
	int makhraj = 1;
	for (int i = 11; i < 100; i++)
		for (int j = i + 1; j < 100; j++)
			if(javab(i, j)) {
				//cout << i << ' ' << j << endl;
				sorat *= i;
				makhraj *= j;
			}
	cout << sorat << " " << makhraj << endl;		
	cout << makhraj / gcd(sorat, makhraj) << endl << clock() << endl;						
	system("pause");
	return 0;
}
bool javab(int i, int j) {
	if (!(i % 11) || !(j % 11))
		return false;
	int a2 = i % 10;
	int a1 = i / 10;
	int b2 = j % 10;
	int b1 = j / 10;
	if (!(b2) || !(a2))
		return false;
	if (a1 == b1)
		if(i * b2 == j * a2)
			return true;		
	if (a1 == b2)
		if(i * b1 == j * a2)
			return true;
	if (a2 == b2)
		if(i * b1 == j * a1)
			return true;
	if (a2 == b1)
		if(i * b2 == j * a1)
			return true;
	return false;
}
int gcd(int n, int m) {
	if(!(n))
		return m;
	if (!(m))
		return n;
	if (n < m)
		swap(n, m);
	return gcd(n % m, m);
}
