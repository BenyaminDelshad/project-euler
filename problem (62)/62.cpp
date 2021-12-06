#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

bool p[10][10000];
bool poly[10];
bool num[10000];
bool ans[40000];
int f;

int Triangle(int n){
	return n * (n + 1) / 2;
}
int Square(int n){
	return n * n;
}
int Pentagonal(int n){
	return n * (3 * n - 1) / 2;
}
int Hexagonal(int n){
	return n * (2 * n - 1);
}
int Heptagonal(int n){
	return n * (5 * n - 3) / 2;
}
int Octagonal(int n){
	return n * (3 * n - 2);
}
void fill_polygonal(){
	for(int i = 1;i <= 150; i++){
		if(Triangle(i) < 10000)
			p[3][Triangle(i)] = true;
		if(Square(i) < 10000)
			p[4][Square(i)] = true;
		if(Pentagonal(i) < 10000)		
			p[5][Pentagonal(i)] = true;
		if(Hexagonal(i) < 10000)
			p[6][Hexagonal(i)] = true;
		if(Heptagonal(i) < 10000)
			p[7][Heptagonal(i)] = true;
		if(Octagonal(i) < 10000)
			p[8][Octagonal(i)] = true;
	}
	return;
}

void bt(int k){
	if(poly[3] & poly[4] & poly[5] & poly[6] & poly[7] & poly[8]){
		k %= 100;
		if(k == f){
			int sum = 0;
			for(int i = 1000;i < 10000; i++){
				if(num[i])
					sum += i;
			}
			if(!ans[sum]){
				cout << sum << endl;
				ans[sum] = true;
			}
		}
	}		 
	int tmp = k;
	k %= 100;
	k *= 100;
	for(int i = 0; i < 100; i++){
		if((k + i) % 100 > 9 && !num[k + i]){
			for(int j = 3; j < 9; j++){
				if((!poly[j]) && p[j][k + i]){
					poly[j] = true;
					num[k + i] = true;
					bt(k + i);
					poly[j] = false;
					num[k + i] = false;
				}
			}
		}
	}
	
}

int main(){
	fill_polygonal();
	for(int i = 1000; i < 10000; i++){
		if(i % 100 > 9){
			f = i / 100;
			for(int j = 3; j < 9; j++){
				if(p[j][i]){
					poly[j] = true;
					num[i] = true;
					bt(i);
					poly[j] = false;
					num[i] = false;
				}
			}
		}
	}
	cout << "Time: " << clock() << endl;
	return 0;
}
