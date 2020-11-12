#include "Tree.h"
treenode<int>* Tree::rebuildTree(int preL,int preR,int inL,int inR){
    if(preL > preR) {
        return nullptr;
    }
    treenode<int>* root = new treenode<int>{};
    //std::vector<int>::iterator it;
    
    std::vector<int> Pre = Tree::preArray();
    std::vector<int> In = Tree::inArray();
    root->data = Pre[preL];
    int R;
    for (R = inL;R <= inR;R++){
        if (In[R] == Pre[preL]){
            break;
        }
    }
    int numLeft = R - inL;
    
    root->lchild = rebuildTree(preL + 1,preL + numLeft,inL, R - 1);
    root->rchild = rebuildTree(preL + numLeft + 1,preR,R + 1,inR);
    return root;
}
