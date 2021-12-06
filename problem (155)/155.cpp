#include <iostream>
#include <algorithm>
#include <iomanip>
#include <set>
#include <vector>
#include <ctime>
#define pb push_back
#define popb pop_back
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;

set<pii>s[20];
vector<ld>v;
ld x = 2*3ll*4*5*6*7*8/*9*10*11*12ll*13*14ll*15*16*17ll*18*/;

int main() {
	
	s[1].insert(pii(x, 1));
	for(ll i = 2; i <= 18; ++i) {	
		for(ll j = 1; j < i; ++j) {
			if(i - j > j) continue;
			for (set<pii>::iterator it = s[j].begin(); it != s[j].end(); ++it) {
				for(set<pii>::iterator it2 = s[i - j].begin(); it2 != s[i - j].end(); ++it2) {
					pii t1 = *it, t2 = *it2;
					s[i].insert( t1 );
					s[i].insert( t2 );
					ll surat = (ll) t1.X * t2.Y + t2.X * t1.Y;
					ll makhraj = (ll) t1.Y * t2.Y;
					ll bmm = __gcd(surat, makhraj);
					surat /= bmm;
					makhraj /= bmm;
					s[i].insert( pii(surat, makhraj) );
					surat = (ll) t1.Y * t2.X + t2.Y * t1.X;
					makhraj = (ll) t1.X * t2.X;
					bmm = __gcd(surat, makhraj);
					surat /= bmm;
					makhraj /= bmm;
					s[i].insert( pii(makhraj, surat) );
				}
			}
		}
	}
	cout << s[18].size() << endl;
	cout << "Time: " << clock() << " mS" << endl;
	system("pause");
	return 0;
}
