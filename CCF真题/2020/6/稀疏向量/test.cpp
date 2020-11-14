#include <iostream>
#include <map>
int main()
{   
    int n,a,b = 0;
    std::cin >> n >> a >> b;

    int index,value,temp = 0;
    long long result = 0;
    std::map<int,int> nummap;
    for (int i = 1;i <= a+b;i++){
        std::cin >> index >> value;
        if(i <= a){
            nummap[index] = value;
        }else if(i > a){
            if (nummap[index] != 0){
                temp = nummap[index] * value;
                result += temp;
            }
        }
    }
    std::cout << result << std::endl;
    return 0;
}


