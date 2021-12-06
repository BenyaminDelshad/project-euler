#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <stack>
#define X first 
#define Y second
using namespace std;
typedef long long ll;
typedef pair<int , int> pii;

ifstream fin("matrix.txt");
const int oo = 1000 * 1000 * 1000;
ll a[80][80];
stack <pii>s;
int dis[80][80];
int d;
pii par[80][80];
char c;
// h: (1: R) (2: D)(3: L) (4: U)
void DFS(int x, int y) {
	if(d + a[x][y] >= dis[x][y]) return;
	d += a[x][y];
	dis[x][y] = d;
	if(x > 0)
		DFS(x - 1, y);
	if(y > 0)
		DFS(x, y - 1);
	if(x < 79)
		DFS(x + 1, y);
	if(y < 79)
		DFS(x, y + 1);
	d -= a[x][y];
}
int main () {
	for(int i = 0; i < 80; ++i)
		for(int j = 0; j < 80; ++j) {
			fin >> a[i][j];
			if(j < 79) fin >> c;
		}
	for(int i = 0; i < 80; ++i)
		for(int j = 0; j < 80; ++j)
			dis[i][j] = oo;
	DFS(0,0);
	cout << dis[79][79] << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
