#include <iostream>
#include <vector>
int main()
{
    int n = 0;
    std::cin >> n;
    std::vector<double> numlist;
    double temp = 0;
    for (int i = 0;i < n;i++){
        std::cin >> temp;
        numlist.push_back(temp);
    }

    int mx,mn = 0;
    double md = 0.0;
    if(numlist[0] < numlist.back()){
        mn = (int)numlist[0];
        mx = (int)numlist.back();
    }else{
        mn = (int)numlist.back();
        mx = (int)numlist[0];
    }
    if (n%2 == 0){
        md = (numlist[n/2]+numlist[n/2-1]) / 2;
        if (md - (int)md > 0 ){
            printf("%d %.1f %d",mx,md,mn);
        }else{
            printf("%d %d %d",mx,(int)md,mn);
        }
    }else{
        md = numlist[n/2];
        std::cout << mx << " " << (int)md <<" " << mn << std::endl;
    }
    return 0;
}

