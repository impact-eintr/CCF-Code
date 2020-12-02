#include <iostream>
#include <stack>
#include <string>
#include <vector>
int main()
{
    int n = 0;
    std::cin >> n;
    std::string cal;
    std::vector<int> numlist;
    for (int i = 0;i < n;i++){
        std::cin >> cal;
        for(std::string::iterator it = cal.begin();it != cal.end();it+=2){
            numlist.push_back(*it-'0');
        }
        
    }
    std::cout << "Hello world" << std::endl;
    return 0;
}

