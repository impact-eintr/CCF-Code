#include <iostream>
int main()
{
    int n,k,t,xl,yd,xr,yu = 0;
    std::cin >> n >> k >> t >> xl >> yd >> xr >> yu;
    
    int stay = 0;
    int pass = 0;
    int passcount = 0;
    int staycount = 0;
    int temp = 0;
    int x,y = 0;
    for (int i = 0;i < n;i++){
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
