#include <iostream>
#include <vector>

int main()
{
    int n = 0;
    std::cin >> n;
    int first = 0;
    int ptemp = 0;

    std::vector<int> pinput;
    std::vector<int> pres;
    std::cin >> first;
    pinput.push_back(first);

    for(int i = 1;i < n;i++){
        std::cin >> ptemp;
        pinput.push_back(ptemp);
    }
    for (int i = 0;i < n;i++){
        if(i == 0 ){
            pres.push_back((pinput[i]+pinput[i+1])/2);
        }else if(i == n-1){
            pres.push_back((pinput[i]+pinput[i-1])/2);
        }else{
            pres.push_back((pinput[i-1] + pinput[i] + pinput[i+1])/3);
        }
    }
    for (int i = 0;i < n;i++){
        printf("%d ",pres[i]);
    }
    return 0;
}

