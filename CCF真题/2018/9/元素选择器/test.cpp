#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <string> 

struct node{
    std::string data;
    std::string attribute;
    std::vector<int> child;
    node *parent = NULL;
    int childnum = 0;//子节点个数
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
            Node[i].layer = (pos+1)/2;
            int pcount = 100;
            for(std::vector<node>::reverse_iterator it = Node.rbegin();it != Node.rend();it++){
                pcount--;
                if(it->layer == Node[i].layer-1){
                    Node[i].parent = &(*it);
                    it->child.push_back(i);
                    it->childnum++;
                    break;
                }
            }
        }else{
            Node[i].data = temp;
            Node[i].layer = (pos+1)/2;
        }
    }

    //std::queue<int> Q;
    //int root = 0;
    //Q.push(root);
    //Node[root].parent = -1;
    //while(!Q.empty()){
    //    int front = Q.front();
    //    std::cout << Node[front].layer << " " << Node[front].data << " " << Node[front].parent-><< std::endl;
    //    Q.pop();
    //    for(long unsigned int i = 0;i < Node[front].child.size();i++){
    //        int child = Node[front].child[i];
    //        Node[child].layer = Node[front].layer+1;
    //        Q.push(child);
    //    }
    //}
    //std::cout << std::endl;

    for (int j = 0;j < m;j++){
        int countres = 0;
        std::string numres ;
        std::getline(std::cin, temp);
        for(int i = 0;i < n;i++){
            if (Node[i].data == temp){
                countres++;
                numres +=  " " + to_string(i+1);
            }else if(temp.substr(0,1) == "#" && Node[i].attribute == temp.substr(1)){
                countres++;
                numres +=  " " + to_string(i+1);
            }else if(temp.find(" ") != std::string::npos && temp.find("#") == std::string::npos){
                std::vector<std::string> str;
                SplitString(temp,str," ");
                std::string strres;
                for (int k = int(str.size()-1);k >= 0;k--){
                    strres += str[k];
                }
                if (Node[n-i].data == str[str.size()-1]) {
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
        std::cout << countres << numres << std::endl;
    }
    return 0;

}
