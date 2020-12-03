#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

int main()
{
    int n = 0;
    std::cin >> n;

    int temp = 0;
    int res = INT_MAX;
    std::vector<int> numlist;
    for(int i = 0;i < n;i++){
        std::cin >> temp ;
        numlist.push_back(temp);
    }
    for (int i = 0;i < n-1;i++){
        for (int j = i;j < n-1;j++ ){
            printf("%d %d\n",numlist[i],numlist[j+1]);
            int tempres =  abs(numlist[i]-numlist[j+1]);
            if (tempres < res){
                res = tempres;
            }
        }
        printf("\n");
    }
    std::cout << res << std::endl;
    return 0;
}

