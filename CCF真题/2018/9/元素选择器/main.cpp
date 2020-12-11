#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <algorithm>

struct node{
    std::string data;
    std::string attribute;
    node *parent = NULL;
    int layer = 200;
};

std::string to_string(int num){
    char temp[64];
    std::sprintf(temp, "%d", num);
    std::string s(temp);
    return s;
}

void SplitString(const std::string& s, std::vector<std::string>& v, const std::string& c)
{
  std::string::size_type pos1, pos2;
  pos2 = s.find(c);
  pos1 = 0;
  while(std::string::npos != pos2)
  {
    v.push_back(s.substr(pos1, pos2-pos1));
 
    pos1 = pos2 + c.size();
    pos2 = s.find(c, pos1);
  }
  if(pos1 != s.length())
    v.push_back(s.substr(pos1));
}

int main()
{
    int n,m = 0;
    std::cin >> n >> m;
    std::cin.ignore();
    std::vector<node> Node(100);
    
    std::string temp;
    for(int i = 0;i < n;i++){
        std::getline(std::cin,temp);
        long unsigned int pos = temp.rfind(".");
        long unsigned int attributepos = temp.find("#");
        if (attributepos != std::string::npos) {
            Node[i].attribute = temp.substr(attributepos+1);
        }
        if (pos != std::string::npos){
            Node[i].data = temp.substr(pos+1,attributepos-pos-2);
            std::transform(Node[i].data.begin(),Node[i].data.end(),Node[i].data.begin(),tolower);
            Node[i].layer = (pos+1)/2;
            for(std::vector<node>::reverse_iterator it = Node.rbegin();it != Node.rend();it++){
                if(it->layer == Node[i].layer-1){
                    Node[i].parent = &(*it);
                    break;
                }
            }
        }else{
            Node[i].data = temp;
            Node[i].layer = (pos+1)/2;
        }
    }
    
    std::vector<std::string> ans;
    for (int j = 0;j < m;j++){
        int countres = 0;
        std::string numres ;
        std::getline(std::cin, temp);
        for(int i = 0;i < n;i++){
            if (temp.find(" ") == std::string::npos && temp.find("#") == std::string::npos){
            	std::transform(temp.begin(),temp.end(),temp.begin(),tolower);
                if(temp == Node[i].data){
                    countres++;
                    numres +=  " " + to_string(i+1);
                }
            }else if(temp.substr(0,1) == "#" && Node[i].attribute == temp.substr(1)){
                countres++;
                numres +=  " " + to_string(i+1);
            }else if(temp.find(" ") != std::string::npos){
                std::vector<std::string> str;
                SplitString(temp,str," ");
                std::string strres;
                for (int k = int(str.size()-1);k >= 0;k--){
                    strres += str[k];
                }
                if (str.size() == 2 && Node[n-i].data == str[1] && Node[n-i].parent->data == str[0] ) {
                    countres++;
                    numres = " " + to_string(n-i+1) + numres;
                }
                if (str.size() > 2 && Node[n-i].data == str[str.size()-1]) {
                    node *test = NULL;
                    int count = 0;
                    std::string tempstrres;
                    for (test = &Node[n-i];test->parent != NULL && count < int(str.size());test = test->parent){
                        count++;
                        tempstrres += test->data;
                    }
                    if (strres == tempstrres){
                        countres++;
                        numres =  " " + to_string(n-i+1) + numres;
                    }
                }
            }
        }
        ans.push_back(to_string(countres) + numres);
    }
    for (int i = 0;i < int(ans.size());i++){
        std::cout << ans[i] << std::endl;
    }
    return 0;
}
