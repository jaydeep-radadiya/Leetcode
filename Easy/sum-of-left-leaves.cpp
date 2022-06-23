class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        else if(root->left!=NULL and root->left->left==NULL and root->left->right==NULL){
            return root->left->val + sumOfLeftLeaves(root->right);
        }
        else{
            return sumOfLeftLeaves(root->left) + sumOfLeftLeaves(root->right);
        }
    }
};