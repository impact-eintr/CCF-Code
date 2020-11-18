#include <iostream>
typedef struct Node{
    int x,y;
    int pass,stay,k;
}Node;
int main()
{
    int n,k,t,xl,yd,xr,yu = 0;
    std::cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    
    for (int i = 0;i < n;i++){
        Node node;
        node.
        for (int j = 0;j < t;j ++){
            std::cin >> x >> y;
            temp = pass;
			printf("%d %d\n",temp,pass);
            if (x >= xl && y >= yd &&
                            x <= xr && y <= yu){
                //std::cout << x0] << x1] << "\n"  << std::endl;
                pass++;
            }
			printf("%d %d\n",temp,pass);
            if (pass > temp){
                stay++;
				printf("%d\n",stay);
                if (j == 2 * (t - 1)){
                     passcount++;
                     if (stay >= k){
                         staycount++;
						printf("staycount = %d",staycount);
                     }
                     pass = 0;
					 stay = 0;
                }
            }
        }
    } 
    std::cout << passcount << std::endl << staycount ;
    return 0;
}
