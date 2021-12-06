#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	int ans = 0, n = 50;
	for(int x1 = 0; x1 <= n; ++x1)
		for(int x2 = 0; x2 <= n; ++x2)
			for(int y1 = 0; y1 <= n; ++y1)
				for(int y2 = 0; y2 <= n; ++y2) {
					if(x1 == x2 && y1 == y2) continue;
					if(x1 == 0 && y1 == 0) continue;
					if(x2 == 0 && y2 == 0) continue;
					if(y1 * y2 == -1 * x1 * x2 || y1 * (y1 - y2) == -1 * x1 * (x1 - x2) || 	y2 * (y1 - y2) == -1 * x2 * (x1 - x2) )
						ans++;
				}
	cout << ans / 2 << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
