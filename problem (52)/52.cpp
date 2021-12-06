#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	
	for(int i = 100000; i < 150000; i++){
		
		int n[7];
		for(int j = 1; j < 7; j++)
			n[j] = j * i;
		bool ans[7] = {};
		int tmp = i;
		int num[6];
		for(int j = 5;j >= 0; j--){
			num[j] = tmp % 10;
			tmp /= 10;	
		}
		sort(num, num + 6);
		do{
			int l = num[5] + num[4] * 10 + num[3] * 100 + num[2] * 1000 + num[1] * 10000 + num[0] * 100000;
			for(int j = 1; j < 7; j++)
				if(l == n[j])
					ans[j] = true;
		}while(next_permutation(num, num + 6));
		if(ans[1] && ans[2] && ans[3] && ans[4] && ans[5] && ans[6]){
			cout << i << endl;
			break;
		}			
	}
	cout << clock() << endl;
	
	system("pause");
	return 0;
}
