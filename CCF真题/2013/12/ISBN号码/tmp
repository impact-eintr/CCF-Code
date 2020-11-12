#include <iostream>
#include <string>
#include <cstdio>

int main()
{
    std::string test;
    std::cin >> test;
    int res = 0;
    int counter = 1;

    for (int i = 0;i < test.size()-1;i++){

        if (test[i] != '-'){
            res += (test[i]-48) * counter;
            counter++;
        }
    }
    signed char ans = res % 11;
    if(ans == test[test.size()-1]-'0'){
        std::cout<<"Right"<<std::endl;
    }else{
        if(ans == 10){
            ans = 'X';
        }else{
            ans = ans + '0';
        }
        test[test.length()-1] = ans;
    }
    std::cout<<test<<std::endl;
    

    return 0;
}

