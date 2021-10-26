/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

// tc : O(n) bcoz we traverse every node once
// recursive
class Solution {
public:
    void preorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        ans.push_back(root->val);
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        preorder(root,ans);
        return ans;
    }
};

// iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(not st.empty()){
            TreeNode *curr = st.top();
            st.pop();
            ans.push_back(curr->val);
            
            if(curr->right)
                st.push(curr->right);
            if(curr->left)
                st.push(curr->left);
        }
        
        return ans;
    }
};