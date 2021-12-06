#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>

using namespace std;

vector<int>p;

bool prime(int a){
	if(a == 2)
		return true;
	if(!(a % 2))
		return false;
	for(int i = 3; i * i <= a; i+= 2)
		if(!(a % i))
			return false;
	return true;
}
int main(){
	for(int i = 2; i < 1000000; i++)
		if(prime(i))
			p.push_back(i);
	for(int i = 3; ; i += 2)
		if(!prime(i)){
			bool x = false;
			for(int j = 0; p[j] < i; j++){
				int tmp = sqrt((i - p[j]) / 2);
				if(tmp * tmp == (i - p[j]) / 2)
					x = true;		
			}
			if(!x){
				cout << i << endl;
				break;
			}
		}
		
	system("pause");
	return 0;
}
