/* CCF201803-1 跳一跳 */
 
#include <iostream>
 
using namespace std;
 
int main()
{
    int a, sum = 0, plus = 0;
    while(scanf("%d", &a) != EOF && a) {
        sum += a;
        if(a == 1)
            plus = 0;
        else if(a == 2) {
            sum += plus;
            plus += 2;
        }
    }
    printf("%d\n", sum);
 
    return 0;
}
 
