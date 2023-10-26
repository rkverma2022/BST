/************************************************************

    Following is the TreeNode class structure

    template <typename T>
    class TreeNode
    {
    public:
        T val;
        TreeNode<T> *left, *right;
        TreeNode() : val(0), left(NULL), right(NULL) {}
        TreeNode(T x) : val(x), left(NULL), right(NULL) {}
        TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
    };


************************************************************/

template<typename T>
void recur(TreeNode<T>* &root, T val)
{
    if(root == nullptr)
    {
        root = new  TreeNode<T>(val);
        return;
    }

    if(val <= root->val)
        recur(root->left, val);
    else
        recur(root->right, val);
    
    return;
}


template <typename T>
TreeNode<T>* insertionInBST(TreeNode<T>* root, T val)
{
    recur(root, val);
    return root;


    // TreeNode<T> *ptr = root;  // Fix the declaration and initialization
    // while (true)
    // {
    //     if (val <= ptr->val)
    //     {
    //         if (ptr->left == nullptr)
    //         {
    //             ptr->left = new TreeNode<T>(val);
    //             break;
    //         }
    //         ptr = ptr->left;
    //     }
    //     else
    //     {
    //         if (ptr->right == nullptr)
    //         {
    //             ptr->right = new TreeNode<T>(val);
    //             break;
    //         }
    //         ptr = ptr->right;
    //     }
    // }

    // return root;
}
