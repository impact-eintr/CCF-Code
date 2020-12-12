#include <iostream>
#include <vector>
#include <algorithm>

struct ball{
    int id;
	int status;
	int pos;
	ball(int pos){
		this->status = 1;
		this->pos = pos;
	}
};

bool cmp(ball a,ball b){
    return a.pos < b.pos;
}

bool idcmp(ball a,ball b){
    return a.id < b.id;
}
int main()
{
	int n ,L ,t = 0;
	std::cin >> n >> L >> t;
	
	std::vector<ball> balllist;
	int temp = 0;
	for (int i = 0;i < n;i++){
		std::cin >> temp;
		ball tempball = ball(temp);
        tempball.id = i;
		balllist.push_back(tempball);
	}
	
    std::sort(balllist.begin(),balllist.end(),cmp);

	for (int i = 0;i < t;i++){
		for (std::vector<ball>::iterator it = balllist.begin();it != balllist.end();it++){
			it->pos += it->status;
            if (it->pos == 0 || it->pos == L){
                it->status *= -1;
            }else if((it-1)->pos == it->pos){
                it->status *= -1;
                (it-1)->status *= -1;
            }
	    }
    }
    std::sort(balllist.begin(),balllist.end(),idcmp);
	for (auto j = balllist.size()-balllist.size();j < balllist.size();j++){
        std::cout << balllist[j].pos  << " ";
	}
}
