#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
// 0: A, 1: L 2: O
bool l;
int r[35];
ll ans;

void BT(int i,bool flag) {
	if(i >= 31) {
		ans++;
		return;
	}
	if(!flag) {
		r[i] = 1;
		flag = true;
		BT(i + 1, flag);
		flag = false;
	}
	if(i == 1 || i == 2) {
		r[i] = 0;
		BT(i + 1, flag);
		r[i] = 2;
		BT(i + 1, flag);
	}
	if(i > 2) {
		if(r[i - 1] != 0) {
			r[i] = 0;
			BT(i + 1, flag);
			r[i] = 2;
			BT(i + 1, flag);
		} 	
		else {
			if(r[i - 2] != 0) {
				r[i] = 0;
				BT(i + 1, flag);
				r[i] = 2;
				BT(i + 1, flag);
			}
			else{
				r[i] = 2;
				BT(i + 1, flag);	
			}
		}
	}
	
}

int main() {
	BT(1, false);
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
