#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure:

    class BinaryTreeNode {
    public:
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;
        
        BinaryTreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if (left) {
              delete left;
            }
            if (right) {
              delete right;
            }
        }
    };

************************************************************/

int findCeil(BinaryTreeNode<int> *node, int x){
    // Write your code here.
    if(node == nullptr)
        return -1;
    

    if(x == node->data)
        return x;
    else if(x < node->data)
    {
        int leftnode = findCeil(node->left, x);

        if(leftnode != -1)
            return leftnode;
        else
            return node->data;
    }
    else{
        return findCeil(node->right, x);
    }



}
