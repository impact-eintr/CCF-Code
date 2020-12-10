#include <iostream>
#include <map>

int main()
{
    int n = 0;
    std::cin >> n;

    std::map<int,int> nummap;
    int temp = 0;
    for (int i = 0;i < n;i++){
        std::cin >> temp;
        nummap[temp]++;
    }

    int low,lowcount = 0;
    int up,upcount = 0;
    for (std::map<int,int>::iterator it = nummap.begin();lowcount < n/2+1;it++){
        low = it->first;
        lowcount += it->second;
    }
    for (std::map<int,int>::reverse_iterator it = nummap.rbegin();upcount < n/2+1;it++){
        up = it->first;
        upcount += it->second;
    }
    if (lowcount == upcount && low == up){
        std::cout << up  << std::endl;
    }else{
        std::cout << "-1" << std::endl;
    }
    return 0;
}
