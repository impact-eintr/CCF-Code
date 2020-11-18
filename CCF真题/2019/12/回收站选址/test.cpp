#include<cstdio>
#include<set>
using namespace std;

class Point{
	public:
	int x;
	int y;
	Point(int _x, int _y):x(_x),y(_y){}
	bool operator < (const Point &rhs) const {
		if(x==rhs.x) return y<rhs.y;
		return x<rhs.x;
	}
	~Point(){}
};

class Test{

    int a;
    const int b;
    static int c;
    const static int d;
    int & e;
    public:
    Test():a(1),b(2),e(a){}
};

int a[10];
auto func(int i) -> int (*)[10]{
    for(int k = 0;k < 10;k++){
        a[k] = k * i;
    }
    return &a;
}

int Test::c = 3;
const int Test::d = 9;
int n;
int ans[5];
set<Point> pts;

bool find(int x, int y){
	if(pts.find(Point(x, y))!=pts.end()) return true;
	return false;
}

int main(){
	scanf("%d",&n);
	int x, y;
	for(int i=0;i<n;++i){
		scanf("%d%d", &x, &y);
		pts.insert(Point(x, y));
	}
	
	set<Point>::iterator it;
	for(it=pts.begin(); it!=pts.end(); it++){
		x=(*it).x; y=(*it).y;
		if(find(x, y+1) && find(x, y-1) && find(x+1, y) && find(x-1, y) ){
			int cnt=0;
			if(find(x-1, y+1)) cnt++;
			if(find(x+1, y+1)) cnt++;
			if(find(x-1, y-1)) cnt++;
			if(find(x+1, y-1)) cnt++;
			ans[cnt]++;
		}
	}
	
	for(int i=0; i<5; ++i){
		printf("%d\n", ans[i]);
	}
	
	return 0;
}
