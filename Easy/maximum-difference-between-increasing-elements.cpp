// Best Time to Buy and Sell Stock

// brute force
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        
        int ans = -1;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[j]>nums[i]){
                    ans = max(ans,nums[j]-nums[i]);
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        
        int minval = INT_MAX;
        int maxdiff = -1;
        for(int i=0;i<n;i++){
            minval = min(minval,nums[i]);
            if(nums[i]>minval){
                maxdiff = max(maxdiff,nums[i]-minval);
            }
        }
        return maxdiff;
    }
};