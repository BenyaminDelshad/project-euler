#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int t(int n);// tedade adad haye nesbat be n avale kamtar az n ba estefade az formule phi(n)

int main(){
	long long cnt = 0;
	for(int i = 2; i <= 1000000; i++)
		cnt  = (long long) cnt + t(i);
	cout << (long long)cnt << endl;
	cout << "Time: " << clock() << " mS" << endl;
	cout << t(87109) << endl;
	system("pause");
	return 0;
}
int t(int n){
	int sorat = 1;
	int makhraj = 1;
	int nn = n;
	for(int i = 2; i * i <= n; i++)
		if(!(n % i)){
			while(!(n % i))
				n /= i;
			sorat *= (i - 1);
			makhraj *= i;
		}
	if(n != 1){
		sorat *= (n - 1);
		makhraj *= n;
	}
	nn /= makhraj;
	nn *= sorat;
	return nn;	
}
