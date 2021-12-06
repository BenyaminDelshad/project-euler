#include<iostream>
#include <algorithm>
#include <ctime>
using namespace std;
typedef long long ll;

bool prime[1000 * 1000 * 10 * 2 + 10];
int me[1000 * 1000 * 20 + 10];
int p[1000 * 1000 * 10 * 2  + 10];
int p2[1000 * 1000 * 20 + 10];
ll n = 2 * 1000 * 1000 * 10;
ll m = 15 * 1000 * 1000;
ll ans;

int main() {
	for(int i = 2; i < n + 1; ++i) {
		prime[i] = true;
		p[i] = 1;
		p2[i] = 1;
	}
	prime[0] = prime[1] = false;
	for(ll i = 2; i <= n; ++i) {
		//if(i % 1000000 == 0) cerr << i / 1000000 << endl;	
		if(prime[i])
			for(ll j = i * i; j <= n; j += i) {
				prime[j] = false;
				if(me[j] == 0) me[j] = i;
			}
	}
	for(ll i = n; i > 1; --i) {
		if(prime[i] || p[i] == 0) continue;
		p[me[i]] += p[i];
		p[i / me[i]] += p[i];
		p[i] = 0;
	}
	for(ll i = m; i > 1; --i) {
		if(prime[i] || p2[i] == 0) continue;
		p2[me[i]] += p2[i];
		p2[i / me[i]] += p2[i];
		p2[i] = 0;
	}			
	for(int i = 2; i <= m; ++i){
		if(prime[i]) p[i] -= p2[i];
		p2[i] = 1;
	}
	for(ll i = n - m; i > 1; --i) {
		if(prime[i] || p2[i] == 0) continue;
		p2[me[i]] += p2[i];
		p2[i / me[i]] += p2[i];
		p2[i] = 0;
	}
	for(int i = 2; i <= n - m; ++i)
		if(prime[i]) p[i] -= p2[i];
	for(int i = 2; i <= n; ++i)
		if(prime[i]) ans += p[i] * i;
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
