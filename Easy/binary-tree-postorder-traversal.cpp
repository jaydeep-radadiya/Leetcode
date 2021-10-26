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
    void postorder(TreeNode *root,vector<int> &ans){
        if(root==NULL) return;
        postorder(root->left,ans);
        postorder(root->right,ans);
        ans.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        postorder(root,ans);
        return ans;
    }
};

// iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        vector<int> ans;
        stack<TreeNode*> st;
        st.push(root);
        
        while(not st.empty()){
            TreeNode *curr = st.top();
            st.pop();

            if(curr->left)
                st.push(curr->left);
            if(curr->right)
                st.push(curr->right);
            ans.push_back(curr->val);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};