

/*
Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *left, *right;
    Node()
    {
        this->data = 0;
        left = NULL;
    }
    Node(int data)
    {
        this->data = data; 
        this->left = NULL;
        this->right = NULL;
    }
    Node(int data, Node* left, Node* right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
};
*/

Node* createBT_DFS(vector<int> &arr, int idx)
{
    if(idx >= arr.size())
        return nullptr;
    
    Node *head = new Node(arr[idx]);

    head->left = createBT_DFS(arr, 2*idx + 1);

    head->right = createBT_DFS(arr, 2*idx + 2);


    return head;
}

Node* createBT_BFS(vector<int>& arr) {
    if (arr.empty())
        return nullptr;

    int n = arr.size();
    vector<int> vis(n, 0); // Fixed the size of the 'vis' vector.
    queue<pair<int, Node*>> q;

    int idx = 0;
    Node* head = new Node(arr[idx]);

    vis[idx] = 1;
    q.push({idx, head});

    while (!q.empty()) {
        int node = q.front().first;
        Node* ptr = q.front().second;
        q.pop();
        for (int j = 1; j <= 2; j++) {
            int child_idx = 2 * node + j;

            if (child_idx < n && !vis[child_idx]) { // Check the bounds before accessing arr.
                vis[child_idx] = 1;

                if (j == 1) { // Left child
                    ptr->left = new Node(arr[child_idx]);
                    q.push({child_idx, ptr->left});
                } else if (j == 2) { // Right child
                    ptr->right = new Node(arr[child_idx]);
                    q.push({child_idx, ptr->right});
                }
            }
        }
    }
    return head;
}

Node* createTree(vector<int>&arr){
    
    // return createBT_DFS(arr, 0);

    return createBT_BFS(arr);
    
    
}
