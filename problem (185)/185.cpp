#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;

ll T[23], L[23][17], target[17];
ll correct[23] = {0,0,1,1,1,1,1,1,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3};
bool is[17][10];

void fill_input() {
	T[1] = 2321386104303845ll ;
	T[2] = 3847439647293047ll ;
	T[3] = 3174248439465858ll ;
	T[4] = 8157356344118483ll ;
	T[5] = 6375711915077050ll ;
	T[6] = 4895722652190306ll ;
	T[7] = 6913859173121360ll ;
	T[8] = 6442889055042768ll ;
	T[9] = 2326509471271448ll ;
	T[10]= 5251583379644322ll ;
	T[11]= 2615250744386899ll ;
	T[12]= 5616185650518293ll ;
	T[13]= 4513559094146117ll ;
	T[14]= 2659862637316867ll ;
	T[15]= 5855462940810587ll ;
	T[16]= 9742855507068353ll ;
	T[17]= 4296849643607543ll ;
	T[18]= 7890971548908067ll ;
	T[19]= 8690095851526254ll ;
	T[20]= 1748270476758276ll ;
	T[21]= 3041631117224635ll ;
	T[22]= 1841236454324589ll ;
	fill(target, target + 17, -1);
	for(int i = 1; i < 23; ++i) {
		for(int j = 15; j >= 0; --j) {
			L[i][j] = T[i] % 10;
			T[i] /= 10ll;
		}		
	}
	for(int i = 0; i < 16; ++i)
		for(int j = 0; j < 10; ++j)
			is[i][j] = true;
	return;	
}
void BT(int level) {
	if(level > 22) {	
		for(int i = 0; i < 16; ++i)
			cout << target[i];
		cout << endl;
		return;
	}
	if(level >21) cerr << level << endl;
	int c = 0;
	for(int i = 0; i < 16; ++i)
		if(target[i] == L[level][i])
			c++;
	if(c > correct[level])
		return;
	if(c == correct[level]) {
		for(int i = 0; i < 16; ++i)
			is[i][L[level][i]] = false;
		BT(level + 1);
		for(int i = 0; i < 16; ++i)
			is[i][L[level][i]] = true;
		return;	
	}
	if(c < correct[level]) {
		for(int i = 0; i < 16; ++i) {
			if(target[i] != -1) continue;
			if(!is[i][L[level][i]]) continue;
			target[i] = L[level][i];
			is[i][L[level][i]] = false;
			BT(level);
			is[i][L[level][i]] = true;
			target[i] = -1;
		}
		return;
	}
	return;
}

int main() {
	fill_input();
	BT(1);
	cout << "Time" << clock() << " mS" << endl;
	system("pause");
	return 0;
}
