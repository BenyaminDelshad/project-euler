#include<iostream>
#include<algorithm>

using namespace std;

int a[11];
int main(){
	long long sum = 0;
	for(int i = 0; i < 10; i++)
		a[i] = i;
	do{
		int tmp1 = 100 * a[1] + 10 * a[2] + a[3];
		int tmp2 = 100 * a[2] + 10 * a[3] + a[4];
		int tmp3 = 100 * a[3] + 10 * a[4] + a[5];
		int tmp4 = 100 * a[4] + 10 * a[5] + a[6];
		int tmp5 = 100 * a[5] + 10 * a[6] + a[7];
		int tmp6 = 100 * a[6] + 10 * a[7] + a[8];
		int tmp7 = 100 * a[7] + 10 * a[8] + a[9];
		if((tmp1 % 2 == 0) && (tmp2 % 3 == 0) && (tmp3 % 5 == 0) && (tmp4 % 7 == 0) && (tmp5 % 11 == 0) && (tmp6 % 13 == 0) && (tmp7 % 17 == 0)){
			long long l = a[9] + 10 * a[8] + 100 * a[7] + 1000 * a[6] + 10000 * a[5] + 100000 * a[4] + 1000 * 1000 * a[3] + 1000 * 1000 * 10 * a[2] + 1000 * 1000 * 100 * a[1] +(long long) 1000 * 1000 * 1000 * a[0];
			sum += l;
		}
	}while(next_permutation(a, a + 10));
	cout << sum << endl;
	system("pause");
	return 0;
}
