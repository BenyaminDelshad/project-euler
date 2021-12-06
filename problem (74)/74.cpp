#include <iostream>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;
typedef long long ll;
bool mark[1000 * 1000 + 50];
int dor[1000 * 1000 + 50];
set<ll>s;
ll fact[15];

int main() {
    fact[0] = 1;
   for(int i = 1; i < 10; ++i)
       fact[i] = fact[i - 1] * i;
   for(int i = 1; i < 1000 * 1000; ++i) {
       s.clear();
       ll tmp2 = i;
       while(true) {
           ll p = 0, tmp = tmp2;
           while(tmp) {
               p += fact[tmp % 10];
               tmp /= 10;
           }
           if(s.find(p) != s.end() || s.size() > 60) {
               dor[i] = s.size();
               //mark[i] = true;
               break;
           }
           /*if(mark[p]) {
               dor[i] = s.size() + dor[p];
               mark[i] = true;
               break;
           }*/
           s.insert(p);
           tmp2 = p;
       }
   }
    ll ans = 0;
    for(int i = 0; i < 1000 * 1000; ++i)
        if(dor[i] >= 59) ans++;
    cout << ans << endl;
    cout << clock() << endl;
    system("pause");
    return 0;
}
