#include <iostream>
#include <vector>
int main()
{
    int n = 0;
    std::cin >> n;
    int numlist[n];
    int Max = 1;
    for (int i = 0;i < n;i++){
        std::cin >> numlist[i];
        if (numlist[i] > Max){
            Max = numlist[i];
        }
    }
    int layer = 2;
    int ans = n;
    int area = 0;
    int w = 0;
    //std::vector<std::vector<int> > test;
    for(int i = 1;i < Max;i++){
        for (int j = 0;j < n;j++){
            if (numlist[j] >= layer){
                w++;
                area = w * layer;
                //printf("i = %d w = %d area = %d\n",i,w,area);
            }else{
                w = 0;
            }
            if(area > ans){
                ans = area;
            }
        }
        w = 0;
        layer++;
    }
    printf("%d\n",ans);
    return 0;
}

