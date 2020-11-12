#include <iostream>
#include <cstdio>
#include <map>
int main()
{
    std::map<int,int> m;
    int n,v;
    std::cin >> n;
    for (int i = 0;i < n;i++){
        std::cin >> v;
        m[v]++;
    }
    int ans,count = 0;
    for (std::map<int,int>::iterator it = m.begin();it != m.end();it++){
        if (it->second > count){
            count = it->second;
            ans = it->first;
        }
    }
    printf("%d",ans);
    return 0;
}

