class Solution {
private:
    set<vector<int>> ss;
    
public:
    void filterVal(vector<int> &nums,int n){
        vector<int> temp;
        int i = 0;
        
        while(n>0){
            if(n&1){
                temp.push_back(nums[i]);
            }
            i++;
            n = n>>1;
        }
        // sort(temp.begin(),temp.end());
        ss.insert(temp);
    }
    
    void generateSubsets(vector<int> &nums,vector<vector<int>> &ans){
        int n = nums.size();
        int len = 1<<n;
        
        for(int i=0;i<len;i++){
            filterVal(nums,i);
        }
        for(auto temp : ss){
            ans.push_back(temp);
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        generateSubsets(nums,ans);
        return ans;
    }
};