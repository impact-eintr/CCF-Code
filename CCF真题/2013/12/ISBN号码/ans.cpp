/* CCF201312-2 ISBN号码 */
 
#include <iostream>
#include <string>
 
using namespace std;
 
int main()
{
    string s;
 
    // 输入数据
    cin >> s;
 
    // 计算识别码
    int sum = 0, j = 1;
    for(int i=0; i<(int)s.length()-1; i++) {
        if(s[i] != '-')
            sum += (s[i] - '0') * j++;
    }
 
    // 识别码转字符
    char c;
    c = sum % 11;
    if(c == 10)
        c = 'X';
    else
        c = c + '0';
 
    // 判断识别码、校正和输出
    if(c == s[s.length()-1])
        cout << "Right" << endl;
    else {
        s[s.length()-1] = c;
        cout << s << endl;
    }
 
    return 0;
}
