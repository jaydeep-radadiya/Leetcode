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

// using 2 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};
        stack<TreeNode*> st1,st2;
        st1.push(root);
        
        while(not st1.empty()){
            TreeNode *curr = st1.top();
            st1.pop();
            st2.push(curr);
            if(curr->left)
                st1.push(curr->left);
            if(curr->right)
                st1.push(curr->right);
        }
        
        vector<int> ans;
        while(not st2.empty()){
            ans.push_back(st2.top()->val);
            st2.pop();
        }
        return ans;
    }
};

// using 1 stack
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