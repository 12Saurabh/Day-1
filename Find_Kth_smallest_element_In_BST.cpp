class Solution {
    int ans=-1;
    vector<int>arr;
    void finder(TreeNode* root, int k,int &i)
    {
        if(root==NULL)
        {
            return;
        }
        finder(root->left,k,i);
        i++;
        if(i==k)
        {
            ans=root->val;
        }
        finder(root->right,k,i);
    }
public:
    int kthSmallest(TreeNode* root, int k) 
    {
        int i=0;
        finder(root,k,i);
        return ans;
    }
};