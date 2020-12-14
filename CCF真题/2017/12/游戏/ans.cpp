#include <iostream>
#include <queue>

int main()
{
    int n,k = 0;
    std::cin >> n >> k;

    std::queue<int> childqueue;
    for (int i = 1;i <= n;i++){
        childqueue.push(i);
    }

    int numcount = 1;
    int head = 0;
    while(!childqueue.empty()){
            head = childqueue.front();
            childqueue.pop();
            if(numcount%k == 0||numcount%10 == k){
            }else{
                childqueue.push(head);
            }
            numcount++;
    }
    std::cout << head << std::endl;
    return 0;
}

