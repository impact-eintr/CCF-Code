#include <iostream>
#include <cmath>

int main()
{
    int n = 0;
    std::cin >> n;
    
    int first =0;
    std::cin >> first;

    int temp = 0;
    int max = 0;
    for (int i = 1;i < n;i++){
        std::cin >> temp;
        if (max < abs(temp-first)){
            max = abs(temp-first);
        }
        first = temp;
    }
    std::cout << max << std::endl;
    return 0;
}

