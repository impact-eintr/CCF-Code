#include <iostream>
#include <map>
#include <cmath>
using namespace std;
int main()
{
    int n = 0;
    cin >> n;

    map<int,int> nummap;
    int temp = 0;
    for (int i = 0;i < n;i++){
        cin >> temp;
        nummap[std::abs(temp)]++;
    }
    int res = 0;
    for(map<int,int>::iterator it = nummap.begin();it != nummap.end();it++){
        if(it->second > 1){
            res++;
        }
    }
    cout << res << endl;
    return 0;
}
