#include <iostream>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <set>
#include <vector>
#define pb push_back
using namespace std;
typedef long long ll;

ll dp[60][60];
set<ll>s;
vector<ll>v;
bool prime[60];
vector<ll>p;
ll n = 51;

int main() {
	for(int i = 0; i <= n; ++i)
		dp[0][i] = 1;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= n; ++j)
			dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
	for(int i = 0; i < n; ++i)
		for(int j = 0; j <= i; ++j)
			s.insert(dp[j][i]);
	while(!s.empty()) {
		v.pb(*s.begin());
		s.erase(s.begin());
	}
	cerr << v.size() << endl;
	fill(prime + 2, prime + n + 1, true);
	for(ll i = 2; i <= n; ++i)
		if(prime[i])
			for(ll j = i * i; j <= n; j += i)
				prime[j] = false;
	for(ll i = 2; i <= n; ++i)
		if(prime[i]) p.pb(i);
	ll ans = 0;
	for(ll i = 0; i < v.size(); ++i) {
		bool flag = true;
		for(int j = 0; j < p.size(); ++j)
			if(v[i] % (p[j] * p[j]) == 0) flag = false;	
		if(flag) ans += v[i];
	}
	cout << ans << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
