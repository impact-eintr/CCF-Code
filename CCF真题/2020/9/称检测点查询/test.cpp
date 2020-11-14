#include <iostream>
#include <algorithm>
#include <map>

bool cmp(std::pair<int,int> a,std::pair<int,int> b){
    if (a.first == b.first)
      return a.second < b.second;
    else
      return a.first < b.first;
}

int main()
{
    int n,X,Y = 0;
    std::cin >> n >> X >> Y;

    int x,y,temp = 0;
    std::pair<int,int> numpair[n];

    for(int i = 1;i <= n;i++){
        std::cin >> x >> y;
        temp = (x - X) * (x - X) + (y - Y) * (y - Y);
        numpair[i-1].first = temp;
        numpair[i-1].second = i;
    }
    std::sort(numpair,numpair+n,cmp);

    for (int i = 0;i < 3;i++){
        printf("%d\n",numpair[i].second);
    }

    return 0;
}

