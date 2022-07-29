class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<TreeNode*> pq;
        queue<TreeNode*> qq;
        
        if (p) {
            
            pq.push(p);
        } 
        if (q) {
            
            qq.push(q);
        }
        
        
        while(!pq.empty() && !qq.empty()) {
            
            p = pq.front();
            q = qq.front();
            pq.pop();
            qq.pop();
            if (p->val != q->val) return false;
            if (p->left && q->left) {
                pq.push(p->left);
                qq.push(q->left);
               
            } else if (p->left || q->left) {
                return false;
            }
            
            if (p->right && q->right) {
                pq.push(p->right);
                qq.push(q->right);
            } else if (p->right || q->right){
                return false;
            }
            
        }
        return pq.empty() && qq.empty() ? true : false;
    }
};