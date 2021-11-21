class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        vector<vector<int>> ans(r,vector<int>(c,0));
        int x = mat.size();
        int y = mat[0].size();
        if(r*c!=x*y) return mat;
        
        vector<int> temp;
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                temp.push_back(mat[i][j]);
            }
        }
        
        int z = 0;
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                ans[i][j] = temp[z++];
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if(row*col!=r*c) return mat;
        vector<vector<int>> output_arr(r,vector<int>(c,0));
        
        int row_num = 0;
        int col_num = 0;
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                output_arr[row_num][col_num++] = mat[i][j];
                if(col_num==c){
                    col_num = 0;
                    row_num++;
                }
            }
        }
        return output_arr;
    }
};

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int row = mat.size();
        int col = mat[0].size();
        if(row*col!=r*c) return mat;
        vector<vector<int>> output_arr(r,vector<int>(c,0));
        
        int row_num = 0;
        int col_num = 0;
        for(int i=0;i<row*col;i++){
            output_arr[i/c][i%c] = mat[i/col][i%col];
        }
        return output_arr;
    }
};