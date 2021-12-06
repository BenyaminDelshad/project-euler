#include <iostream>
#include <algorithm>
#include <vector>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;

vector<ll>p[1000 * 100 + 10];
bool mark[1000 * 100 + 10];
pii rad[1000 * 100 + 10];

int main() {
	mark[1] = true;
	for(ll i = 2; i <= 1000 * 100; ++i)
		if(!mark[i]) {
			mark[i] = true;
			for(ll j = i; j <= 1000 * 100; j += i){
				p[j].push_back(i);
				mark[j] = true;
			}
		}
	rad[1].X = rad[1].Y = 1;
	for(int i = 2; i <= 1000 * 100; ++i) {
		rad[i].X = 1;
		rad[i].Y = i;
		for(int j = 0; j < p[i].size(); ++j)
			rad[i].X *= p[i][j];
	}
	sort(rad + 1, rad + 100 * 1000 + 1);
	cout << rad[100 * 100].Y << endl;
	system("pause");
	return 0;
}
