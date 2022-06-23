class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans.push_back(abs(nums[j]-nums[i]));
            }
        }
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};