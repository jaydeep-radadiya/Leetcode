class Solution {
public:
    bool canJump(vector<int>& arr) {
        int n = arr.size();
        vector<bool> dp(n,true);
        
        for(int i=n-2;i>=0;i--){
            // if(arr[i]==0) dp[i] = false;
            bool is_reachable = false;
            for(int j=i+1;j<n && j-i<=arr[i];j++){
                if(dp[j]==true){
                    is_reachable = true;
                    break;
                }
            }
            if(is_reachable==true)
                dp[i] = true;
            else
                dp[i] = false;
        }
        return dp[0];
    }
};