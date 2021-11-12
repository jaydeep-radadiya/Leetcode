class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n) return {};
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        int x = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j] = original[x++];
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(original.size()!=m*n) return {};
        vector<vector<int>> ans(m, vector<int>(n,0));
        
        for(int i=0;i<original.size();i++){
            ans[i/n][i%n] = original[i];
        }
        return ans;
    }
};