class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int row = accounts.size();
        int col = accounts[0].size();
        
        int mx = INT_MIN;
        for(int i=0;i<row;i++){
            int sum = accumulate(accounts[i].begin(),accounts[i].end(),0);
            mx = max(mx,sum);
        }
        return mx;
    }
};