#include<bits/stdc++.h>
 
using namespace std;
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
typedef long long ll;
typedef pair <ll, ll> P;
struct markdown
{
    int type;
    string s;
};
 
bool isspace(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
            return false;
    }
    return true;
}
 
string standard(string s)
{
    int pos1 = 0, pos2 = s.length() - 1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != ' ')
        {
            pos1 = i;
            break;
        }
    }
    for (int i = s.length() - 1; i >= 0; i--)
    {
        if (s[i] != ' ')
        {
            pos2 = i;
            break;
        }
    }
    string temp = s.substr(pos1, pos2 - pos1 + 1);
    return temp;
}
 
vector <markdown> v;
 
int main()
{
    //freopen("C://Users/Administrator/Desktop/4.txt","r",stdin);
    IOS;
    int w;
    cin >> w;
    ll ans = 0;
    string str;
    while (getline(cin, str))
    {
        if (!isspace(str))
            break;
    }
    if (str.size() >= 2 && str[1] == ' ' && str[0] == '*')
    {
        v.push_back({1, standard(str.substr(2))});
    }
    else
    {
        v.push_back({2, standard(str)});
    }
    bool check = false;
    while (getline(cin, str))
    {
        if (isspace(str))
            check = true;
        else
        {
            if (check)
            {
                check = false;
                if (str.size() >= 2 && str[1] == ' ' && str[0] == '*')
                {
                    v.push_back({1, standard(str.substr(2))});
                }
                else
                {
                    v.push_back({2, standard(str)});
                }
            }
            else
            {
                markdown &bac = v.back();
                if (bac.type == 1 || bac.type == 3)
                {
                    if (str.length() >= 2 && str[1] == ' ' && str[0] == ' ')
                    {
                        bac.s += " ";
                        bac.s += standard(str.substr(2));
                    }
                    else if (str.size() >= 2 && str[1] == ' ' && str[0] == '*')
                    {
                        v.push_back({3, standard(str.substr(2))});
                    }
                    else
                    {
                        v.push_back({2, standard(str)});
                    }
                }
                else
                {
                    if (str.size() >= 2 && str[1] == ' ' && str[0] == '*')
                    {
                        v.push_back({1, standard(str.substr(2))});
                    }
                    else
                    {
                        bac.s += " ";
                        bac.s += standard(str);
                    }
                }
            }
        }
    }
//    for(auto &x:v)
//    {
//        cout<<x.type<<" "<<x.s<<endl;
//    }
    for (int i = 0; i < v.size(); i++)
    {
        string &str = v[i].s;
        if (v[i].type != 3 && i > 0)
        {
            //cout<<"kong"<<endl;
            ans++;
        }
        if (v[i].type != 2)
        {
            if (str.size() == 0)
            {
                //cout<<"kong"<<endl;
                ans++;
            }
            else
                for (int i = 0; i < str.length(); i += (w - 3))
                {
                    while (i < str.length() && str[i] == ' ')
                        i++;
                    //cout<<str[i]<<endl;
                    ans++;
                }
        }
        else
        {
            for (int i = 0; i < str.length(); i += w)
            {
                while (i < str.length() && str[i] == ' ')
                    i++;
                //cout<<str[i]<<endl;
                ans++;
            }
        }
    }
    cout << ans << endl;
    return 0;
}
