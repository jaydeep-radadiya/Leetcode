class Solution {
public:
    void filterVal(vector<int> &nums,vector<vector<int>> &ans,int n){
        vector<int> temp;
        int i = 0;
        
        while(n>0){
            if(n&1){
                temp.push_back(nums[i]);
            }
            i++;
            n = n>>1;
        }
        ans.push_back(temp);
    }
    
    void generateSubsets(vector<int> &nums,vector<vector<int>> &ans){
        int n = nums.size();
        int len = 1<<n;
        
        for(int i=0;i<len;i++){
            filterVal(nums,ans,i);
        }
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        generateSubsets(nums,ans);
        return ans;
    }
};