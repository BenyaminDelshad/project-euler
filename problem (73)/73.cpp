#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int gcd(int a, int b){
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a < b)
		swap (a , b);
	return gcd(a % b, b);	
}

int main(){
	int cnt = 0;
	for(int i = 1; i <= 6000; i++)
		for(int j = i * 2 + 1; j < i * 3  && j <= 12000; j++)
			if(gcd(i, j) == 1)
				cnt++;
	cout << cnt << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
