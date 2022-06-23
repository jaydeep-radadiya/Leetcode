class Solution {
public:
    void rotate(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();
        
        // transpose of matrix
        for(int i=0;i<r;i++){
            for(int j=i+1;j<c;j++){
                swap(arr[i][j],arr[j][i]);
            }
        }
        
        // reverse every row
        for(int i=0;i<r;i++){
            reverse(arr[i].begin(),arr[i].end());
        }
    }
};