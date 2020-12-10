#include <iostream>

int main()
{
    int n = 0;
    std::cin >> n;

    const int up = 1;
    const int down = -1;

    int first ,second = 0;
    std::cin >> first >> second;

    int flag = second-first<0 ? -1:1;
    int tempflag = 0;
    int temp = 0;
    int res = 0;
    for (int i = 2;i < n;i++){
        std::cin >> temp;
        if (temp-second < 0){
            tempflag = down;
        }else{
            tempflag = up;
        }
        if(tempflag != flag){
            res++;
        }
        flag = tempflag;
        second = temp;
    }
    std::cout << res << std::endl;

    return 0;
}

