#include<iostream>
#include<algorithm>
#include<ctime>
using namespace std;

int gcd(int a, int b){
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a < b)
		swap (a , b);
	return gcd(a % b, b);	
}

bool cmp(pair<int, int>a, pair<int, int>b){
	return (long long)a.first * b.second < (long long)a.second * b.first;
}

pair<int, int>frc[1000000];

int main(){
	int cnt = 0;
	for(int i = 1; i < 500000; i++)
		for(int j = i * 7 / 3; j <= i * 7 / 3 + 1 && j < 1000001; j++)
			if(gcd(i, j) == 1)
				frc[cnt++] = make_pair(i, j);
	sort(frc, frc + cnt, cmp);
	for(int i = cnt - 1; i >= 0; i--)
		if(frc[i].first == 3 && frc[i].second == 7){
			cout << frc[i - 1].first << endl;
			break;			
		}
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
