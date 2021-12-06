#include<iostream>
#include<vector>

using namespace std;

vector<int>d;
vector<int>prm;
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
	int sum = 0;
	for(int i = 2; i < 1000000; i++)
		if(prime(i) && sum + i < 1000000){
			prm.push_back(i);
			sum += i;
		}
	int Max = 0;
	int ans;
	for(int i = 0; i < prm.size(); i++)
		for(int j = i + 1; j < prm.size();j++){
			int s = 0;
			for(int k = i; k <= j; k++)
				s += prm[k];
			if(prime(s) && j - i + 1 > Max){
				Max = j - i + 1;
				ans = s;		
			}
		}
	cout << ans << endl << clock() << endl;
	system("pause");
	return 0;
}	
