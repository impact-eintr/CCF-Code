#include <cstdio>
#include "stringhash.h"

int main()
{
    int m,n;
    scanf("%d%d",&n,&m);
    for(int i = 0;i < n;i++){
        scanf("%s",S[i]);
        int id = hashFunc(S[i],3);
        hashTable[id]++;
    }

    for(int i = 0;i < m;i++){
        scanf("%s",temp);
        int id = hashFunc(temp,3);
        printf("%d\n",hashTable[id]);
    }
    return 0;
}

int hashFunc(char s[],int len){
    int id = 0;
        for(int i = 0;i < len;i++){
            id = id * 26 + (s[i] - 'a');
        }
    return id;
}


