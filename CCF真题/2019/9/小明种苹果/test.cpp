#include <iostream>
#include <vector>

int main()
{
    int N,M;
    std::cin >> N >> M;
    
    int apples = 0;
    int applenums = 0;
    int Max = 0;
    int index = 0;
    for (int i = 1;i <= N;i++){
        std::cin >> apples;
        int temp = 0;
        int acount = 0;
        for (int j = 0;j < M;j++){
            std::cin>>temp;
            acount += -1 * temp;
        }
        if (acount > Max){
            Max = acount;
            index = i;
        }
        applenums += apples - acount;
    }
    std::cout<<applenums<<" "<<index<<" "<<Max<<std::endl;
    
    return 0;
}

