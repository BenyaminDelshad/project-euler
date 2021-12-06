#include <iostream>
#include <algorithm>
#include <vector>
#include <ctime>
#include <cmath>
#include <fstream>
#define pb push_back
#define popb pop_back
using namespace std;
typedef long long ll;

ifstream fin("input.txt");

ll arr[16][16];
ll n = 15, m = 7;
bool mark[16];
vector<int>s;
ll Maxi, Maxs, Max;

void fill_arr() {
	for(int i = 1; i < 16; ++i)
		for(int j = 1; j < 16; ++j)
			fin >> arr[i][j];
}
int main() {
	fill_arr();
	int i[8] = {};
	for(i[1] = 1; i[1] < 16; ++i[1]) {
		mark[i[1]] = true;	
		for(i[2] = i[1] + 1; i[2] < 16; ++i[2]) {
			mark[i[2]] = true;	
			for(i[3] = i[2] + 1; i[3] < 16; ++i[3]) {
				mark[i[3]] = true;
				for(i[4] = i[3] + 1; i[4] < 16; ++i[4]) {
					mark[i[4]] = true;
					for(i[5] = i[4] + 1; i[5] < 16; ++i[5]) {
						mark[i[5]] = true;
						for(i[6] = i[5] + 1; i[6] < 16; ++i[6]) {
							mark[i[6]]= true;
							for(i[7] = i[6] + 1; i[7] < 16; ++i[7]) {
								mark[i[7]] = true;	
								//----------------------------------------------
								for(int j = 1; j < 16; ++j)
									if(!mark[j])
										s.pb(j);
								int t[7] = {1, 2, 3, 4, 5, 6, 7};
								ll Maxt = 0;
								do{
									Maxi = 0;
									for(int j = 1; j < 8; ++j)
										Maxi += arr[i[j]][t[j - 1]];
									if(Maxt < Maxi)
										Maxt = Maxi;
								}while(next_permutation(t, t + 7));
								int r[8] = {8, 9, 10, 11, 12, 13, 14, 15};
								ll Maxr = 0;
								do{
									Maxs = 0;
									for(int i = 0; i < 8; ++i)
										Maxs += arr[s[i]][r[i]];
									if(Maxr < Maxs)
										Maxr = Maxs;
								}while(next_permutation(r, r + 8));
								if(Max < Maxr + Maxt)
									Max = Maxr + Maxt;
								while(s.size()) s.popb();
								//----------------------------------------------
								mark[i[7]] = false;
							}	
							mark[i[6]] = false;
						}
						mark[i[5]] = false;
					}
					mark[i[4]] = false;
				}
				mark[i[3]] = false;
			}
			mark[i[2]] = false;
		}
		mark[i[1]] = false;
	}
	cout << Max << endl;	
	cout << "Time:" << clock() << " mS" << endl;
	system("pause");
	return 0;
}
