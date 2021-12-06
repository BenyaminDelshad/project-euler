#include <iostream>
#include <algorithm>
using namespace std;

int a[1000 * 1000 * 10 + 50];

void Ok(int n){
	if(a[n])
		return;
	int num[10] = {};
	int s = 0;
	int tmp = n;
	while(tmp){
		num[s++] = tmp % 10;
		tmp /= 10;
	}
	int next = 0;
	for(int i = 0; i < s; i++)
		next += (num[i] * num[i]);
	if(a[next]){
		a[n] = a[next];
		return;
	}
	Ok(next);
	a[n] = a[next];
}
int main(){
	a[1] = 1;
	a[89] = 89;
	for(int i = 1; i < 1000 * 1000 * 10; i++)
		Ok(i);
	int ans = 0;
	for(int i = 1; i < 1000 * 1000 * 10; i++)
		if(a[i] == 89)
			ans++;
	cout << ans << endl;
	cout << "Time: " << clock() << "mS" << endl;
	system("pause");
	return 0;
}
