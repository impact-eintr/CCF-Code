#include <iostream>

int main() {
	int r, y, g = 0;
	std::cin >> r >> y >> g;
	int n = 0;
	std::cin >> n;
	int k, t = 0;
	int timeres = 0;
	for (int i = 0; i < n; i++) {//考虑到开发了的咖啡店
		if (k == 0 || k == 1) {
			timeres += t;
		} else if (k == 2) {
			timeres += t + r;
		}
	}
	std::cout << timeres << std::endl;
	return 0;
}
