#include <iostream>

void test(){
    int temp = 0;
    int score =0;
    std::cin >> temp;
    int pre = temp;
    score += temp;
    int tempscore = 0;

    while (temp != 0){
        std::cin >> temp;
        if (temp == 1){
            tempscore = 0;
            score += 1;
        }else if(temp == 2){
            if(pre == 1){
                score += 2;
            }else if(pre == 2){
                tempscore += 2;
                score += tempscore+2;
            }
        }
        pre = temp;//更新前值
    }
    std::cout << score;
}

void arraytest(){

}

int main()
{
    test();
    
    return 0;
}
