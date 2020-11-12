#ifndef TREENODE_H__
#define TREENODE_H__
#include <queue>
#include <cstdio>
#include <vector>

template<typename T>struct treenode{
    T data;
    int layer;
    treenode* lchild;
    treenode* rchild;
};
class Tree
{
    public:
    treenode<int>* Create(int[],int);
    treenode<int>* AddNode(int v);
    void InsertNode(treenode<int>* &,int);
    void SearchNode(treenode<int>*,int,int);
    std::vector<int> preArray(){
        return this->Pre;
    }
    std::vector<int> inArray(){
        return this->In;
    }
    std::vector<int> posttArray(){
        return this->Post;
    }
    std::vector<int> layerArray(){
        return this->Layer;
    }

    //遍历
    void prorder(treenode<int>* root);
    void inorder(treenode<int>* root);
    void postororder(treenode<int>* root);
    void layerorder(treenode<int>* root);
    
    //重建树
    treenode<int>* rebuildTree(int,int,int,int);
    
    Tree() {};
    ~Tree() {};

    private:
    std::vector<int> Pre;
    std::vector<int> In;
    std::vector<int> Post;
    std::vector<int> Layer;
};
#endif
