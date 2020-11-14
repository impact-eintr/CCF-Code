#include<iostream>
using namespace std;
 
typedef struct Node{
    int x,y;
    int through,danger,k;
}Node;
 
int main(){
    int t,k,n,x1,y1,x2,y2;
    int through=0,danger=0;
    cin>>t>>k>>n>>x1>>y1>>x2>>y2;
    for(int i=0;i<t;i++){
        Node node;
        node. through=0;
        node. danger=0;
        node. k=0;
        for(int j=0;j<n;j++){
            int x,y;
            cin>>x>>y;
            if(x1<=x && x<=x2 && y1<=y && y<=y2){
                node. through=1;
                node. k++;
                if(node.k==k){
                    node. danger=1;
                }
            }else node. k=0;
        }
        through+=node. through;
        danger+=node. danger;
    }
    cout<<through<<endl<<danger;
}
