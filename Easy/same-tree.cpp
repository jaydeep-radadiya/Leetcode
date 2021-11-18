class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL and q==NULL) return true; // p and q are both null
        if(p==NULL or q==NULL) return false; // one of p and q is null
        if(p->val!=q->val) return false;
        return isSameTree(p->left,q->left) and isSameTree(p->right,q->right);
    }
};

// iterative solution
class Solution {
public:
    bool isSameTree(TreeNode* t1, TreeNode* t2) {
        queue<TreeNode *> q;
        q.push(t1);
        q.push(t2);
        while(q.size()>0){
            TreeNode *x1 = q.front();
            q.pop();
            TreeNode *x2 = q.front();
            q.pop();
            if(x1==NULL and x2==NULL) continue;
            if(x1==NULL or x2==NULL) return false;
            if(x1->val!=x2->val) return false;
            q.push(x1->left);
            q.push(x2->left);
            q.push(x1->right);
            q.push(x2->right);
        }
        return true;
    }
};