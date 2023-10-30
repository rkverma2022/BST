/*************************************************************
    Following is the Binary Tree node structure

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

*************************************************************/

template <typename T>
BinaryTreeNode<T>* deleteNode(BinaryTreeNode<T>* root, int key) {
    if (root == nullptr)
        return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } else {
        // Node with only one child or no child
        if (root->left == nullptr) {
            BinaryTreeNode<T>* temp = root->right;
            delete root;
            return temp;
        } else if (root->right == nullptr) {
            BinaryTreeNode<T>* temp = root->left;
            delete root;
            return temp;
        }

        // Node with two children, get the in-order successor
        BinaryTreeNode<T>* successor = root->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }

        // Copy the in-order successor's data to this node
        root->data = successor->data;

        // Delete the in-order successor
        root->right = deleteNode(root->right, successor->data);
    }
    return root;
}
