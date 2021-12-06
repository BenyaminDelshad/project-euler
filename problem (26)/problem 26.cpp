#include <iostream>

using namespace std;

int circle(int t);

int main() {
	int max = 1;
	for (int i = 1; i < 1000; i++) {
		int t = circle(i);
		if(t > max)
			max = i;
	}
	cout << max << endl << clock() << endl;
	system("pause");
	return 0;
}
int circle(int t) {
	if ((!(t % 2)) || (!(t % 5)))
		return 0;
	int r = 0;
	int a[1000] = {};
	bool b = true;
	int p = 1;
	int c = 1;
	while (b) {
		r = p % t;
		p = 10 * r;	
		if (a[r]) {
			b = false;
			c -= a[r];
		}
		else
			a[r] = c++;
	}	
	return c ;
}
