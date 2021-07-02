class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx_sum = nums[0];
        int temp = 0;
        
        for(int i=0;i<n;i++){
            temp = max(nums[i],temp+nums[i]);
            mx_sum = max(mx_sum,temp);
        }
        return mx_sum;
    }
};