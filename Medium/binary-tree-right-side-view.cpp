// first method
class Solution {
private:
    void solve(TreeNode *root,vector<int> &arr,int curr_level){
        if(root==NULL) return;
        if(curr_level==arr.size()){
            arr.push_back(root->val);
        }
        solve(root->right,arr,curr_level+1);
        solve(root->left,arr,curr_level+1);
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> arr;
        solve(root,arr,0);
        return arr;
    }
};

// second method
class Solution {
private:
    int mx_level = INT_MIN;
    vector<int> arr;
    
public:
    void solve(TreeNode *root,int curr_level){
        if(root==NULL) return;
        if(mx_level<curr_level){
            arr.push_back(root->val);
            mx_level = curr_level;
        }
        solve(root->right,curr_level+1);
        solve(root->left,curr_level+1);
    }
    
    vector<int> rightSideView(TreeNode* root) {
        solve(root,0);
        return arr;
    }
};