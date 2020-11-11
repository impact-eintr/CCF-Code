#ifndef STRINGHASH_H__
#define STRINGHASH_H__
const int maxn = 100;
char S[maxn][5],temp[5];
int hashTable[26 * 26 * 26 + 10];

int hashFunc(char *S,int len);

#endif
