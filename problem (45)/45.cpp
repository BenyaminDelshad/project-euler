#include <iostream>
#include <set>

int main() {
	long long int i;
	std::set <long long int> hex, pent;
	for (i = 286; (hex.find((i * (i + 1)) / 2) == hex.end()) || (pent.find((i * (i + 1)) / 2) == pent.end()); ++i) {
		 pent.insert((i * (3 * i - 1)) / 2);
		 hex.insert(i * (2 * i - 1));
	}
	std::cout << ((i * (i + 1)) / 2) << '\n';
	system("pause");
	return 0;
}
