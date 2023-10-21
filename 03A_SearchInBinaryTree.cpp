/*
    Following is the Binary Tree node structure:

    template <typename T>
    class BinaryTreeNode
    {
    public:
        T data;
        BinaryTreeNode<T> *left, *right;
        BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
        BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
        BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
    };

*/

bool searchInBST(BinaryTreeNode<int> *root, int x) {
    // Write your code here.
    if(root == NULL)
        return false;

    if(root->data == x)
        return true;
    

    bool f1 = false;
    bool f2 = false;
    if(x > root->data)
        f1 = searchInBST(root->right, x);
    else
        f2 = searchInBST(root->left, x);
    
    return f1 || f2;
}
