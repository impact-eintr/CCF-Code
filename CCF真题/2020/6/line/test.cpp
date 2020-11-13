#include <iostream>
#include <set>
#include <vector>
#include<algorithm>

typedef struct Point{
    int x,y;
    char label;
}Point;

int main()
{
    //std::map<std::vector<int> ,char> pmap;
    std::vector<Point> pmap;
    int n,m = 0;
    std::cin >> n >> m;

    int x,y = 0;
    char label = 'A';
    for (int i = 0;i < n;i++){
        Point input{};
        std::cin >> x >> y >> label;
        input.x = x;
        input.y = y;
        input.label = label;
        std::cout << input.x << " " << input.y << " " << input.label << std::endl;
        pmap.push_back(input);
    }
    
    double b,w1,w2 = 0;//double负数可能有坑
    
    //不用除法 就要多开辟空间存储
    for (int i = 0;i < m;i++){
        std::set<int> up,down;
        std::cin >> b>>w1>>w2;
        for (int j = 0;j < n;j++){
            if (w1 * pmap[j].x + b < -1 * w2 * pmap[j].y ){
                up.insert(pmap[j].label);
            }else{
                down.insert(pmap[j].label);
            }
        }
        if (up.size() > 1|| down.size() > 1)
            std::cout<<"No\n";
        else std::cout<<"Yes\n";
    }
    return 0;
}

