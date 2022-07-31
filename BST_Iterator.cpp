class BSTIterator {
public:
    vector<int> inorder_nodes;
    void inorder(TreeNode* root) {
        if (root == nullptr) return;
        inorder(root->right);
        inorder_nodes.push_back(root->val);
        inorder(root->left);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int node = inorder_nodes.back();
        inorder_nodes.pop_back();
        return node;
    }
    
    bool hasNext() {
        return !inorder_nodes.empty();
    }
};
