#include <iostream>
#include <vector>
int main()
{
    int n = 0;
    std::cin >> n;

    std::vector<int> alist;
    std::vector<int> blist;
    int a, b = 0;
    for(int i = 0;i < n;i++){
        std::cin >> a >> b;
        alist.push_back(a);
        alist.push_back(b);
    }

    for (int i = 0;i < n;i++){
        std::cin >> a >> b;
        blist.push_back(a);
        blist.push_back(b);
    }

    int res = 0;
    for (int i = 0;i < 2*n;i+=2){
        a = alist[i]>blist[i]?alist[i]:blist[i];
        b = alist[i+1]<blist[i+1]?alist[i+1]:blist[i+1];
        res += b-a;
    }
    std::cout << res << std::endl;
    return 0;
}
