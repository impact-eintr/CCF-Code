#include <iostream>

int main()
{
    int n;
    int step = 0;
    std::cout << "input n : \n";
    std::cin>>n ;

    while(n != 1){
        if (n % 2 == 0){
            n = n/2;
        }else{
            n = (3 * n + 1)/2;
        }
            step++;
    }

    std::cout << step << std::endl;
    return 0;
}

