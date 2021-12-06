#include<iostream>
using namespace std;

bool is_prime(int n){
	if(n == 2)
		return true;
	if(n % 2 == 0 || n == 1)
		return false;
	for(int i = 3; i * i <= n; i++)
		if(n % i == 0)
			return false;
	return true;   
}
   
int main(){
   	int side;
   	int numbers;
   	int primes;
   	int p;
   	primes = 0;
   	numbers = 1;
   	p = 100;
   	for(side = 3 ; p >= 10 ; side += 2){
      numbers += 4;
      if(is_prime(side * side)) primes++;
      if(is_prime(side * side - side + 1)) primes++; 
      if(is_prime(side * side - 2 * side + 2)) primes++; 
      if(is_prime(side * side - 3 * side + 3)) primes++;
      p = (100 * primes) / numbers;
	}
	cout << side - 2 << endl;
   	system("pause");
	return 0;
}
