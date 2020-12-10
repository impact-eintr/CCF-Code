#include <iostream>

int main() {
	int r, y, g = 0;
	std::cin >> r >> y >> g;
    int count = r+y+g;
	int n = 0;
	std::cin >> n;

	int k, t = 0;
    long long timeres = 0;
    long long temptime = 0;
	for (int i = 0; i < n; i++) {
        std::cin >> k >> t;
        if(k == 1){
            temptime = (timeres-t+count)%count;
        }else if(k == 2){
            temptime = (timeres-t-r+count)%count;
        }else if (k == 3){
            temptime = (timeres-t-y-r+count)%count;
        }else{
            timeres += t;
            continue;
        }
        if(temptime < g){
        }else{
            timeres += count-temptime;
        }
	}
    std::cout << timeres << std::endl;
	return 0;
}
