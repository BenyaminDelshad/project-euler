#include<iostream>

using namespace std;

bool mark[1000000];

int t(int n){
	int counter = 0;
	for(int i = 2; i <= n; i++)
		if(!(n % i)){
			counter++;
			while(!(n % i))
				n /= i;
		}
	return counter;
}	
int main(){
	for(int i = 2; i < 1000000; i++)
		if(t(i) == 4){
			mark[i] = true;
			if(mark[i - 1] && mark[i - 2] && mark[i - 3]){
				cout << i - 3 << endl;
				break; 
			}
		}
	cout << clock() << endl;
	system("pause");
	return 0;
}
