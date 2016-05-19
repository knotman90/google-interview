#include <iostream>
#include<array>

using namespace std;



template<class PAYLOAD>
class node {
  public:
    node(PAYLOAD _p): p(_p) {}
    node* left;
    node*right;
    PAYLOAD p;
};

template<class ARRAY,class PAYLOAD>
int search(const ARRAY& a,int start, const int end, const PAYLOAD& p) {
    while(start <=end)
        if(a[start]==p)
            return start;
        else
            start++;
}

template<class PAYLOAD,size_t SIZE>
node<PAYLOAD>* reconstructTree(array<PAYLOAD,SIZE> preorder,uint& preIndex,uint instart, uint inend,
                               array<PAYLOAD,SIZE> inorder) {

    printf("- %d, %d,%d\n",preIndex,instart,inend);
    if(instart > inend)
        return nullptr;

    node<PAYLOAD>* p = new node<PAYLOAD>(preorder[preIndex++]);

    if(instart == inend)
        return p;

    int idx = search(inorder,instart,inend,p->p);
    printf("Left %d ",idx);
    p->left = reconstructTree(preorder,preIndex,instart,idx-1,inorder);
    printf("rght %d ",idx);
    p->right = reconstructTree(preorder,preIndex,idx+1,inend,inorder );

    return p;


}
template<class PAYLOAD>
void inOrderVisit(node<PAYLOAD>* r) {
    if(r) {
        inOrderVisit(r->left);
        printf(" %d ",r->p);
        inOrderVisit(r->right);
    }
}

template<class PAYLOAD>
void preOrderVisit(node<PAYLOAD>* r) {
    if(r) {
        printf(" %d ",r->p);
        preOrderVisit(r->left);
        preOrderVisit(r->right);
    }
}


#define size (8)
int main() {

    array<uint,size> preorder = {1,2,4,5,3,7,6,8};
    array<uint,size> inorder  = {4,2,5,1,6,7,3,8};

    uint preIdx =0;
    auto n = reconstructTree<uint>(preorder,preIdx,0,size-1,inorder);
    inOrderVisit(n);
    printf("\n");
    preOrderVisit(n);
    return 0;
}
