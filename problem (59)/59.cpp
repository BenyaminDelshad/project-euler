#include <iostream>
#include <algorithm>
#include<fstream>
using namespace std;
// 32 ta 125 - 35 ta 38
// a ta z == 97 ta 122

ifstream fin("cipher1.txt");

int out[5000];
int nums = 0;
	
void input();
string convert(int a, int b, int c);
bool check(string matn);
	
int main() {
	input();
	int counter = 0;
	/*for(int i = 0; i < 128; i++)
		cout << i << " : " << (char) i << endl;*/
	for(int i = 97; i < 123; i++)
		for(int j = 97; j < 123; j++)
			for(int k = 97; k < 123; k++){
				string matn = convert(i, j, k);
				if(check(matn)){
					cout << i <<' ' << j << ' '  << k << endl << matn << endl;
					int sum = 0;
					for(int h = 0; h < nums; h++)
						sum += (int)matn[h];
					cout << sum << endl;
				}	
			}
	system("pause");
	return 0;
}
void input(){
	int n;
	char alaki;
	while(fin >> n){
		out[nums++] = n;
		fin >> alaki;
	}	
}
string convert(int a, int b, int c){
	string s;
	s.resize(1500);
	for(int i = 0; i < nums; i += 3)
		s[i] = (char)(a ^ out[i]);
	for(int i = 1; i < nums; i += 3)
		s[i] = (char) (b ^ out[i]);
	for(int i = 2; i < nums; i += 3)
		s[i] = (char) (c ^ out[i]);
	return s;
}		
bool check(string matn){
	bool x = true;
	bool y = false;
	for(int i = 0; i < nums; i++){
		if((matn[i] >= 35 && matn[i] <= 38) || (matn[i] < 32 || matn[i] > 125))
			x = false;	
	}
	for(int i = 0; i < nums - 2; i++)
		if(matn[i] == 't' && matn[i + 1] == 'h' && matn[i + 2] == 'e')
			y = true;
	return (x & y);
}		
