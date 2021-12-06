#include <iostream>
#include <algorithm>
#include <cmath>
#include <fstream>
using namespace std;

ifstream fin("base_exp.txt");
pair<int,pair<int, int> > in[1100];

bool cmp(pair<int,pair<int,int> > a, pair<int, pair<int,int> > b){
	long double q = (double) a.second.first * log(a.first);
	long double w = (double) b.second.first * log(b.first);
	return (double)q < (double)w;
}	
int main(){
	char c;
	int h, j;
	for(int i = 0; i < 1000; i++){
		fin >> h >> c >> j;
		in[i].first = h;
		in[i].second.first = j;
		in[i].second.second = i + 1;
	}
	sort(in, in + 1000, cmp);
	cout << in[999].second.second << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
