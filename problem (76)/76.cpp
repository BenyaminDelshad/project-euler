#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

int ans = 0;
int adad = 100;
void BT(int n){
	if(!(adad)){
		ans++;
		return;
	}
	if(n > adad || n > 99)
		return;
	for(int i = 0; n * i <= adad; i++){
		adad -= n * i;
		BT(n + 1);
		adad += n * i;
	}
	
	
}
int main(){
	BT(1);
	cout << ans << endl;
	cout << "Time: " << clock() << "mS" << endl;
	return 0;
}
