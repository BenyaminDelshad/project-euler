#include<iostream>
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
	for(int i = 1000; i < 10000; i++)
		if(prime(i))
			p.push_back(i);
	for(int i = 0; i < p.size(); i++){
		for(int j = i + 1; j < p.size(); j++){
			for(int k = j + 1; k < p.size(); k++){
				if(p[j] - p[i] == p[k] - p[j] && p[i] != 1487){
					/*bool tmp[10] = {};
					tmp[p[i] % 10] = true;
					tmp[(p[i] / 10) % 10] = true;
					tmp[(p[i] / 100) % 10] = true;
					tmp[p[i] / 1000] = true; 
					tmp[p[j] % 10] = true;
					tmp[(p[j] / 10) % 10] = true;
					tmp[(p[j] / 100) % 10] = true;
					tmp[p[j] / 1000] = true;
					tmp[p[k] % 10] = true;
					tmp[(p[k] / 10) % 10] = true;
					tmp[(p[k] / 100) % 10] = true;
					tmp[p[k] / 1000] = true;
					int counter = 0;
					for(int t = 0; t < 10; i++)
						if(tmp[t])
							counter++;
					*/
					int a[4];
					a[3] = p[i] % 10;
					a[2] = (p[i] / 10) % 10;
					a[1] = (p[i] / 100) % 10;
					a[0] = p[i] / 1000;
					bool r = false, rr = false;
					do{
						int tmp = a[0] * 1000 + a[1] * 100 + a[2] * 10 + a[3];
						if(tmp == p[j])
							r = true;
						if(tmp == p[k])
							rr = true;	
					}while(next_permutation(a, a + 4));
					if(r & rr){
						cout << p[i] << p[j] << p[k] << endl;
						break;		 
					}		
				}
			}
		}
	}
	cout << clock() << endl;
	system("pause");
	return 0;
}
