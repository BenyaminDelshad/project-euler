#include<iostream>
#include<vector>

using namespace std;

vector<int> primes;
bool a[9000][9000];
vector<int>ans[100000];
vector<int>ans2[100000];

int num(long long n){
	int ans = 0;
	while(n){
		n = (long long)n / 10;
		ans++;
	}
	return ans;
}
int pow(int a, int b){
	int tmp = 1;
	for(int i = 0; i < b; i++)
		tmp *= a;
	return tmp;
}
bool is_prime(int n){
	if(n == 2)
		return true;
	if(n % 2 == 0)
		return false;
	for(int i = 3; i * i <= n; i += 2)
		if(n % i == 0)
			return false;
	return true;			
}
int main(){
	for(int i = 2; i < 9000; i++)
		if(is_prime(i))
			primes.push_back(i);
	//cerr << "ASV" << endl;		
	for(int i = 0; i < primes.size(); i++)
		for(int j = 0; j < primes.size(); j++)
			if(is_prime(primes[i] * pow(10,num(primes[j])) + primes[j]) && is_prime(primes[j] * pow(10,num(primes[i])) + primes[i])) 		
				a[primes[i]][primes[j]] = true;
	int c = 0;
	//cerr << "avf" << endl;
	for(int i = 0; i < 9000; i++)
		for(int j = 0; j < 9000; j++)
			if(a[i][j]){
				ans[c].push_back(i);
				ans[c++].push_back(j);
			//	cerr << i << ' ' << j << endl;
			}
		//cerr << "adfvb" << endl;	
	int cc = 0;		
	for(int i = 0; i < c; i++)
		for(int j = i + 1; j < c; j++)
			if(a[ans[i][0]][ans[j][0]] && a[ans[i][1]][ans[j][0]] && a[ans[i][0]][ans[j][1]] && a[ans[i][1]][ans[j][1]]){
				ans2[cc].push_back(ans[i][0]);
				ans2[cc].push_back(ans[i][1]);
				ans2[cc].push_back(ans[j][0]);
				ans2[cc++].push_back(ans[j][1]);		
			}
	int mn = 100000000;		
	for(int i = 0; i < cc;i++)		
		for(int j = 0; j < primes.size();j++)
			if(a[ans2[i][0]][primes[j]] && a[ans2[i][1]][primes[j]] && a[ans2[i][2]][primes[j]] && a[ans2[i][3]][primes[j]]){
				int sum = ans2[i][0] + ans2[i][1] + ans2[i][2] + ans2[i][3] + primes[j];
				if(sum < mn)
					mn = sum;		
			}
	cout << mn << endl << clock() << endl;
	system("pause");
	return 0;
}
