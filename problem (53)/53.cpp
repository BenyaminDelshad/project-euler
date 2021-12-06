#include <iostream>

using namespace std;

const int MAX = 128;
unsigned long long t[MAX][MAX];

int main() {
   t[0][0] = 1;
   for (int n = 1; n <= 100; ++n) {
      t[n][0] = 1;
      for (int r = 1; r <= n; ++r) {
         t[n][r] = t[n - 1][r - 1] + t[n - 1][r]; 
      }
   }
   int count = 0;
   for(int i = 1 ;i < 101; i++){
		int tmp = 0;
		while(t[i][tmp] <= 1000000) tmp++;
		if(tmp <= i / 2)
			count += (i - 2 * tmp + 1);
	}
	cout << count << endl;
   system("pause");
   return 0;
}
