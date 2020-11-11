#include "Tree.h"
treenode<int>* Tree::AddNode(int v){
    treenode<int> *Node = new treenode<int>;
    Node->data = v;
    Node->lchild = Node->rchild = nullptr;
    return Node;
}
//x 搜索值 newdata修改值
void Tree::SearchNode(treenode<int> *root,int x,int newdata){
    if(root == nullptr){
        return;
    }
    if(root->data == x){
        root->data = newdata;
    }
    SearchNode(root->lchild,x,newdata);
    SearchNode(root->rchild,x,newdata);
}
void Tree::InsertNode(treenode<int>* &root,int x){
    if(root == nullptr){
        root = AddNode(x);
        return;
    }
    if (x > 5){
        printf("%d%s\n",x,"left");
        InsertNode(root->lchild,x);
    }else{
        printf("%d%s\n",x,"right");
        InsertNode(root->lchild,x);
    }

}

treenode<int>* Tree::Create(int data[],int n){
    treenode<int> *root = nullptr;
    for(int i = 0;i < 5;i++){
        InsertNode(root,data[i]);
    }
    for(int i = 5;i < n;i++){
        InsertNode(root,data[i]);
    }
    return root;
}

void Tree::prorder(treenode<int>* root){
    if (root == nullptr){
        return;
    }
    printf("%d \t",root->data);
    prorder(root->lchild);
    prorder(root->rchild);
}
void Tree::inorder(treenode<int>* root){
    if (root == nullptr){
        return;
    }
    inorder(root->lchild);
    printf("%d \t",root->data);
    inorder(root->rchild);

}
void Tree::postororder(treenode<int>* root){
    if (root == nullptr){
        return;
    }
    postororder(root->lchild);
    postororder(root->rchild);
    printf("%d \t",root->data);

}

void Tree::layerorder(treenode<int>* root){
    std::queue<treenode<int>*> q;
    q.push(root);
    while(!q.empty()){
        treenode<int>* now = q.front();
        q.pop();
        printf("%d ",now->data);
        if(now->lchild != nullptr){
            q.push(now->lchild);
        }
        if(now->rchild != nullptr){
            q.push(now->rchild);
        }
        printf("\n");
    }

}

int main(void){
    int data[] = {1,2,3,4,5,6,7,8,9,10};
    //int data[] = {1,2,3};
    Tree testtree = Tree();
    treenode<int>* testroot = testtree.Create(data,10);
    testtree.postororder(testroot);
    printf("\n");
    testtree.prorder(testroot);
    printf("\n");
    testtree.inorder(testroot);
    printf("\n");
    testtree.layerorder(testroot);

}
