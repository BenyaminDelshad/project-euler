#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <fstream>
#define X first
#define Y second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ld, ld> point;

ifstream fin("triangles.txt");
const ld eps = 0.0001;
point A, B, C;
ll ans;

int main() {
	for(int i = 0; i < 1000; ++i) {
		fin >> A.X >> A.Y >> B.X >> B.Y >> C.X >> C.Y;
		ld a = sqrt( (B.X - C.X) * (B.X - C.X) + (B.Y - C.Y) * (B.Y - C.Y) );
		ld b = sqrt( (A.X - C.X) * (A.X - C.X) + (A.Y - C.Y) * (A.Y - C.Y) );
		ld c = sqrt( (B.X - A.X) * (B.X - A.X) + (B.Y - A.Y) * (B.Y - A.Y) );
		ld P = (a + b + c) / 2;
		ld S = sqrt( P * (P - a) * (P - b) * (P - c) );
		ld Ao = sqrt( A.X * A.X + A.Y * A.Y );
		ld Bo = sqrt( B.X * B.X + B.Y * B.Y );
		ld Co = sqrt( C.X * C.X + C.Y * C.Y );
		ld PAoB = (Ao + Bo + c) / 2;
		ld PAoC = (Ao + Co + b) / 2;
		ld PBoC = (Bo + Co + a) / 2;
		ld SAoB = sqrt( PAoB * (PAoB - Ao) * (PAoB - Bo) * (PAoB - c) );
		ld SAoC = sqrt( PAoC * (PAoC - Ao) * (PAoC - Co) * (PAoC - b) );
		ld SBoC = sqrt( PBoC * (PBoC - Bo) * (PBoC - Co) * (PBoC - a) );
		ld S2 = SAoB + SAoC + SBoC;
		if(S2 - S <= eps)
			ans++;
	}
	cout << ans << endl;
	system("pause");
	return 0;
}
