// tc : O(r*c)
class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        vector<vector<int>> arr(col,vector<int>(row)); // this is main thing
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                arr[j][i] = matrix[i][j];
            }
        }
        return arr;
    }
};