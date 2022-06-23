// tc : O(2^n)
class Solution {
public:
    int solve(vector<int> &arr,int n){
        if(n<0)
            return 0;
        else
            return max(arr[n]+solve(arr,n-2),solve(arr,n-1));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        return solve(nums,n-1);
    }
};

// memoization
class Solution {
public:
    int solve(vector<int> &arr,vector<int> &dp,int n){
        if(n<0)
            return 0;
        if(dp[n]!=-1)
            return dp[n];
        else
            return dp[n] = max(arr[n]+solve(arr,dp,n-2),solve(arr,dp,n-1));
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n,-1);
        return solve(nums,dp,n-1);
    }
};