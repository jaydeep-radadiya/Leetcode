class Solution {
private:
    typedef long long ll;
    bool is_valid(TreeNode *root,ll low,ll high){
        if(root==NULL) return true;
        int val = root->val;
        // use -> when it's pointer
        // use . when it's object
        return val>low && val<high && is_valid(root->left,low,val) && is_valid(root->right,val,high);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return is_valid(root,LONG_MIN,LONG_MAX);
    }
};