class Solution {
public:
    int jump(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> dp(n);
        dp[n-1] = 0;
        for(int i=n-2;i>=0;i--){
            int min_steps = INT_MAX-2;
            for(int j=i+1;j<n && j-i<=arr[i];j++){
                min_steps = min(min_steps,dp[j]);
            }
            dp[i] = min_steps+1;
        }
        return dp[0];
    }
};