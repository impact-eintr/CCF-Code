#include <iostream>
#include <set>

int main()
{
    int N = 0;
    int M = 0;
    std::set<int> appleset;
    int applecount = 0;
    std::cin >> N;

    for (int i = 0; i < N;i++){
        std::cin >> M;
        int oldapplenum = 0;
        int applenum = 0;
        
        int temp = 0;
        int op = 0;
        int orgiapples = 0;
        //记录每棵树的初始值
        std::cin >> orgiapples;
        applenum = orgiapples;
        for (int j = 1;j < M;j++){
            std::cin >> temp;
            if(temp > 0){
                oldapplenum = applenum + op;
                op = 0;//操作因子归0
                applenum = temp;
                if (oldapplenum != temp){
                    appleset.insert(i);
                }
            }else{
                op += temp;
            }
        }
        applenum += op;
        applecount += applenum;
    }

    int threecount = 0;
    for (std::set<int>::iterator it = appleset.begin();it != appleset.end();it++){
        if(appleset.find(((*it)+1)%N)!= appleset.end()&&appleset.find(((*it)+2)%N)!=appleset.end()){
        threecount++;
        }
    }

    std::cout << applecount << " " << appleset.size() << " " << threecount <<std::endl;
    return 0;
}

