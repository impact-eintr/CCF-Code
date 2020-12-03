#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;
    int res = n/10;
    if (res >= 3){
        if(res >= 5){
            if(res % 5 >= 3){
                res += 2 * (res/5) + 1;
            }else{
                res += 2 * (res/5);
            }
        }else{
            res += res/3;
        }
    }
    std::cout << res << std::endl;
    return 0;
}

