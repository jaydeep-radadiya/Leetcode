class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        
        while(not q.empty()){
            int sz = q.size();
            vector<int> level;
            for(int i=0;i<sz;i++){
                TreeNode *curr = q.front();
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                level.push_back(curr->val);
            }
            ans.push_back(level);
        }
        
        return ans;
    }
};