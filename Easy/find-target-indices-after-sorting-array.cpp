class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(nums[i]==target){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

// optimised
// counting sort
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ans;
        
        int cntless = 0;
        int cntequal = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==target) cntequal++;
            else if(nums[i]<target) cntless++;
        }
        for(int i=cntless;cntequal>0;i++){
            ans.push_back(i);
            cntequal--;
        }
        return ans;
    }
};