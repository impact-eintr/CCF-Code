#include <iostream>

int main()
{
    int n,k;
    std::cin >> n >> k;
    int tmp = 0;
    long weight = 0;
    int friends = 0;

    for (int i = 0;i < n;i++){
        std::cin >> tmp;
        if(i == 0){
            weight = tmp;
            if(weight >= k){
                friends++;
            }
            continue;
        }
        weight +=tmp;
        if(weight >= k){
            friends++;
            weight = 0;
        }else if(i == n-1){
            friends++;
        }
    }
    std::cout << friends << std::endl;
    return 0;
}

