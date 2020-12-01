#include <iostream>
#include <cmath>
#include <vector>
#include <string>
#include <cstring>
#include <cstdlib>
//html 转 10进制
std::vector<int> test(std::string rgb){
	if (rgb.size() == 2)  //只有2位字符
        rgb += std::string(5, rgb.back());  //字符串末尾添加5个末尾字符
        else if (rgb.size() == 4)  //只有4位字符
            rgb = "#" + std::string(2, rgb[1]) + std::string(2, rgb[2]) + std::string(2, rgb[3]);  //添加成为6位
    std::string color = rgb.substr(1);
    std::vector<int> RGB;
    for(int i = 0;i < 6;i+=2){
 	    RGB.push_back(std::stoi(color.substr(i,i+1),0,16));
    }
    return RGB;
}

std::string handle_color(std::vector<std::vector<int> > colors,int p,int q){
    int R = 0;
    int G = 0;
    int B = 0;
    for (std::vector<std::vector<int> >::iterator it = colors.begin();it != colors.end();it++){
        R += (*it)[0];
        G += (*it)[1];
        B += (*it)[2];
    }
    R = R / (p * q);
    G = G / (p * q);
    B = B / (p * q);
    std::string r = std::string(R);

}

int main()
{
    std::string strbackground = "\033[48;2;";
    std::string strend = "\033[0m";
    int m,n = 0;
    std::cin >> m >> n;
    int p,q = 0;
    std::cin >> p >> q;

    std::string tempcolor;
    std::vector<int> color;
    std::vector<std::vector<int> > colorlist[m/p];
    std::vector<std::string> reslist;
    for (int i = 0;i < n;i++){
        for(int j = 0;j < m ;j++){   
            std::cin >> tempcolor;
            color = test(tempcolor);
            if (i % (n/p) == 0 ){//新的一个像素行
                //非初始行
                if ( colorlist[i/p].begin() != colorlist[i/p].end()){
                    //计算上一像素行的输出值
                    for (int k = 0;k < m/p;k++){
                        reslist.push_back(handle_color(colorlist[k]),p,q);
                        colorlist[k].clear();//清空存储体
                    }
                }
                //colorlist[i/p].push_back(color);
            }
            colorlist[i/p].push_back(color);
        }
    }
    for (std::vector<std::string>::iterator it = reslist.begin();it != reslist.end();it++ ){
        std::cout << *it;

    }
    std::cout << "\033[38;2;255;0;0mHello\033[0m \033[48;2;0;0;255m\033[48;2;255;255;255mworld\033[0m" << std::endl;
    return 0;
}

