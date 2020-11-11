#ifndef TREENODE_H__
#define TREENODE_H__
#include <queue>
#include <cstdio>

template<typename T>struct treenode{
    T data;
    treenode* lchild;
    treenode* rchild;
};
class Tree
{
    public:
    Tree() {};
    treenode<int>* AddNode(int v);
    void SearchNode(treenode<int>*,int,int);
    void InsertNode(treenode<int>* &,int);
    treenode<int>* Create(int[],int);

    //遍历
    void prorder(treenode<int>* root);
    void inorder(treenode<int>* root);
    void postororder(treenode<int>* root);
    void layerorder(treenode<int>* root);

    ~Tree() {};

    private:
};
#endif
