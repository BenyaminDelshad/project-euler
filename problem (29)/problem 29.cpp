#include <iostream>

using namespace std;

long long int pow(int az, int bz);
bool logs(int n, int m);
void tkamel(int n, int &a, int &b);

int main() {
	int a, b;
	bool aa[101][101] = {};
	int counter = 0;
	for (int i = 2; i < 101; i++)
		for (int j = 2; j < 101; j++)
			if (!(aa[i][j])) {
				tkamel(i, a, b);
				b *= j;
				for (int k = 2; k < b; k++)
					if (!(b % k) && (k != b / j)) 
						if (pow(a , k) < 101 && pow(a , k) > 0 && b / k < 101)
							aa[pow(a , k)][b / k] = true;
			}
	for (int i = 2; i < 101; i++)
		for (int j = 2; j < 101; j++)
			if (!(aa[i][j]))
				counter++;
	cout << counter << endl << clock() << endl;
	system("pause");
	return 0;
}
long long int pow( int az, int bz) {
	long long int zarb = 1;
	for (int i = 0; i < bz; i++)
		zarb *= az;
	return zarb;	
}
void tkamel(int n, int &a, int &b){
	a = 2;
	while (!(logs(n, a))) 		
		a++;
	b = 0;
	while (n > 1) {
		n /= a;
		b++;
	
	}
}
bool logs(int n, int m) {
	int counter = -1;
	int s = 1;
	int tmp = n;
	while(tmp){
		tmp /= m;
		counter++;
	}
	for (int i = 0; i < counter; i++)
		s *= m;	
	if (s == n)
		return true;
	return false;
}
