/* CCF201312-4 有趣的数 */
 
#include <iostream>
#include <cstring>
 
using namespace std;
 
const long long mod = 1000000007;
const int MAXN = 1000;
const int MAXS = 5;
long long dp[MAXN+1][MAXS+1];
 
 
int main()
{
    int n;
 
    cin >> n;
 
 	memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    for(int i=2;i<=n;++i)
    {
        dp[i][0]=1;//只含2
        dp[i][1]=(2*dp[i-1][1]%mod+dp[i-1][0])%mod;//只含2、0  末尾0或2、末尾0
        dp[i][2]=(dp[i-1][2]+dp[i-1][0])%mod;//只含2、3 末尾3
        dp[i][3]=(2*dp[i-1][3]%mod+dp[i-1][1])%mod;//只含2、0、1 末尾2或1、末尾1
        dp[i][4]=((2*dp[i-1][4]%mod+dp[i-1][2])%mod+dp[i-1][1])%mod;//只含2、0、3 末尾1或3、末尾0、末尾3
        dp[i][5]=((2*dp[i-1][5]%mod+dp[i-1][4])%mod+dp[i-1][3])%mod;//含4个数字  末尾1或3
    }
    cout << dp[n][5] << endl;
 
    return 0;
}
