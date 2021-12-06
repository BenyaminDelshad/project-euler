#include<iostream>
#include<algorithm>
using namespace std;

int num(unsigned long long n){
	int ans = 0;
	while(n){
		n = (long long)n / 10;
		ans++;
	}
	return ans;
}

int main(){
	unsigned long long a = 1, b = 2;
	unsigned long long c, d;
	int counter = 0;
	for(int i = 0; i < 1000; i++){
		c = (long long)a + (long long)2 * b;
		d = (long long)a + b;
		a = c;
		b = d; 
		//cout << a << '/' << b << endl;
		if(num(a) > num(b))
			counter++;
	}
	cout << counter << endl;
	system("pause");
	return 0;
}
