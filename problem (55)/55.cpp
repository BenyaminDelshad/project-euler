#include<iostream>
#include<algorithm>
using namespace std;

int num(unsigned long long n);
bool palindrom(unsigned long long n);
unsigned long long next_num(unsigned long long n);

int main(){
	int ans = 0;
	for(int i = 1; i < 10000; i++){
		int counter = 0;
		unsigned long long r = i;
		r = next_num(r);
		while(counter < 48 && !palindrom(r)){
			counter++;
			r = next_num(r);
		}
		if(counter == 48)
			ans++;
	} 
	cout << ans << endl;
	system("pause");
	return 0;
}
int num(unsigned long long n){
	int ans = 0;
	while(n){
		n = (long long)n / 10;
		ans++;
	}
	return ans;
}
unsigned long long next_num(unsigned long long n){
	int t[25];
	unsigned long long tmp = n;
	for(int j = num(n) - 1; j >= 0; j--){
		t[j] = tmp % 10;
		tmp /= 10;
	}
	reverse(t, t + num(n));
	unsigned long long ans = 0;
	unsigned long long y = 1;
	for(int i = num(n) - 1; i >= 0; i--){
		ans = (long long)ans +(long long) y * t[i];
		y =(long long) y * 10;
	}
	ans = (long long)ans + n;
	return (long long)ans;
}
bool palindrom(unsigned long long n){
	int t[25];
	unsigned long long tmp = n;
	for(int j = num(n) - 1; j >= 0; j--){
		t[j] = tmp % 10;
		tmp /= 10;
	}
	int t2[25];
	for(int i = 0; i < num(n); i++)
		t2[i] = t[i];
	reverse(t, t + num(n));
	bool x = true;
	for(int i = 0; i <= num(n) / 2; i++)
		if(t[i] != t2[i])
			x = false;
	return x;
}
