
// In The Name of God
#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <fstream>
using namespace std;

ifstream fin("network.txt");

const int MAX_N = 100 + 5;
const int oo = 1000 * 1000 * 100;

int n ,m, sum, kol;
vector<int>g[MAX_N];
vector< pair<int, pair<int, int> > > edges;
vector<pair<int, int> > ans;
int par[MAX_N];

void input();
void output();
// disjoint set functions:
void set_par();
void Union (int a, int b);
int find_par(int v);
// disjoint set functions End.

int main(){
	input();
	set_par();
	sort(edges.begin(), edges.end());
	for(int i = 0; i < m; i++){
		int u = edges[i].second.first;
		int v = edges[i].second.second;
		if(find_par(u) != find_par(v)){
			ans.push_back(make_pair(u, v));
			Union(u, v);
			sum += edges[i].first;
		}
	}
	//output();
	cout << kol - sum << endl;
	system("pause");
	return 0;
}
void input(){
	n = 40;
	int ss[40][40];
	for(int i = 0; i < 40; ++i)
		for(int j = 0; j < 40; ++j)
			fin >> ss[i][j];
	for(int i = 0; i < 40; ++i) {
		for(int j = i + 1; j < 40; ++j) {
			if(ss[i][j] < oo) {
				kol += ss[i][j];
				m++;
				edges.push_back(make_pair(ss[i][j], make_pair(i, j)));
				g[i].push_back(j);
				g[j].push_back(i);
			}	
		}
	}
	return;
}
void set_par(){
	for(int i = 0; i < n; i++)
		par[i] = i;
	return;
}
void Union(int a, int b){
	par[find_par(a)] = find_par(b);
	return;
}
int find_par(int v){
	if(par[v] == v)
		return v;
	return par[v] = find_par(par[v]);
}	
void output(){
	for(int i = 0; i < ans.size(); i++)
		cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << endl;
	return;
}	
