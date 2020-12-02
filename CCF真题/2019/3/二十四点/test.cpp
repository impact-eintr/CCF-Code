#include <iostream>
#include <vector>
int main()
{
    int n = 0;
    std::cin >> n;
    std::string cal;
    std::vector<int> numlist;
    std::string ans;
    for (int j = 0;j < n;j++){
        std::cin >> cal;
        if(!numlist.empty()){
            numlist.clear();
        }
        numlist.push_back(cal[0]-'0');
        for(int i = 1;i < 7;i+=2){
            if (cal[i] == '-'){
                numlist.push_back(-1 * (cal[i+1]-'0'));
            }else if(cal[i] == 'x' || cal[i] == '/'){
                numlist.back() = (cal[i] == 'x'?numlist.back()*(cal[i+1]-'0') : numlist.back()/(cal[i+1]-'0'));
            }else{
                numlist.push_back(cal[i+1]-'0');
            }
        }
        int res = 0;
        for (std::vector<int>::iterator it = numlist.begin();it != numlist.end();it++){
            res += *it;
        }
        if (res == 24){
            ans += "yes\n";
        }else{
            ans += "No\n";
        }
    }
    std::cout << ans << " ";
    return 0;
}
