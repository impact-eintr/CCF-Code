#include <iostream>

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

void get_next(char* T,int *next){
    int i,j;
    i = 1;
    j = 0;
    next[1] = 0;
    while (i < T[0]){
        if(j == 0||T[i] == T[j]){
            ++i;
            ++j;
            next[i] = j;
        }
        else
          j = next[j];
    }
}

int Index_KMP(char *S,char *T,int pos){
    int i = pos;
    int j = 1;
    int next[255];
    get_next(T,next);
    while(i <= S[0] && j <= T[0]){

    }

}
