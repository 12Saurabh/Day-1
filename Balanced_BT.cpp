class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return check(root) != -1;
    }
    
    int check(TreeNode* root) {
        if (root == nullptr) return 0;
        
        int left = check(root->left);
        int right = check(root->right);
        
        if (left == -1 || right == -1 || abs(left-right) > 1) return -1;
        
        return max(left, right) + 1;
        
    }
};