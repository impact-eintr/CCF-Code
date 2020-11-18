#include <iostream>

int help(int x){
    int a = x;
    while(a != 0){
        if (a % 10 == 7){
            return 1;
        }
        a = a / 10;
    }
    return 0;
}

int main()
{
    int N = 0;
    int n = 0;
    int x = 1;
    int index = 0;
    int res[4] = {0,0,0,0};
    std::cin >> N;
    while(n < N){
        if (x % 7 == 0 || help(x) ){
            res[index%4]++;
            index++;
            x++;
            continue;
        }
        index++;//玩家循环
        x++;//数字累加
        n++;//有效数字累加
    }
    for(int i = 0;i < 4;i++){
        std::cout << res[i] <<"\n";
    }
    return 0;
}

