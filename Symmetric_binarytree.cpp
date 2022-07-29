class Solution {
public:
    bool inordert(TreeNode* root, TreeNode* root1)
    {
        int ans = true;

        if(root == NULL && root1 == NULL) return true;
        if(root == NULL || root1 == NULL) return false;
        if(root->val != root1->val) return false;
        
        ans = ans & inordert(root->left, root1->right);
        if(ans == false) return ans;
        
        ans = ans & inordert(root->right, root1->left);
        
        return ans;
    }
    bool isSymmetric(TreeNode* root) 
    {
        return inordert(root, root);
    }
};