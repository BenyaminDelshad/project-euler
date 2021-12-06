#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;

bool avl[1000 * 1000 * 100 + 1];
ll ans;

int main() {
	for(ll i = 1; i < 10000; ++i)
		for(ll j = i + 1; j <= 10000; ++j)
			if(j * (j + 1) * (2 * j + 1) / 6ll - (i-1) * ((i-1) + 1) * (2 * (i-1) + 1) / 6ll <= 1000 * 1000 * 100)
				avl[j * (j + 1) * (2 * j + 1) / 6ll - (i-1) * ((i-1) + 1) * (2 * (i-1) + 1) / 6ll] = true;
	int tmp;
	for(int i1 = 1; i1 < 10; i1++){
		tmp = i1;
		if(avl[tmp])
			ans += (ll)tmp;
	}
	for(int i1 = 1; i1 < 10; i1++){
		tmp = 10 * i1 + i1;
		if(avl[tmp])
			ans+= (ll) tmp; 
	}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++){
			tmp = i1 * 100 + i2 * 10 + i1;
			if(avl[tmp])
				ans+= (ll) tmp;
		}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++){		
			tmp = 1000 * i1 + 100 * i2 + 10 * i2 + i1;
			if(avl[tmp])
				ans+= (ll) tmp; 
		}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++){
				tmp = 10000 * i1 + 1000 * i2 + 100 * i3 + 10 * i2 + i1;
				if(avl[tmp])
					ans+= (ll) tmp;
			}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++){			
				tmp = 100000 * i1 + 10000 * i2 + 1000 * i3 + 100 * i3 + 10 * i2 + i1;
				if(avl[tmp])
					ans+= (ll) tmp; 
			}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++)
				for(int i4 = 0; i4 < 10; i4++){
					tmp = 1000000 * i1 + 100000 * i2 + 10000 * i3 + 1000 * i4 + 100 * i3 + 10 * i2 + i1;
					if(avl[tmp])
						ans+= (ll)tmp;
				}
	for(int i1 = 1; i1 < 10; i1++)
		for(int i2 = 0; i2 < 10; i2++)
			for(int i3 = 0; i3 < 10; i3++)
				for(int i4 = 0; i4 < 10; i4++){				
					tmp = 10000000 * i1 + 1000000 * i2 + 100000 * i3 + 10000 * i4 + 1000 * i4 + 100 * i3 + 10 * i2 + i1;
					if(avl[tmp])
						ans+= (ll) tmp;	
				}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
