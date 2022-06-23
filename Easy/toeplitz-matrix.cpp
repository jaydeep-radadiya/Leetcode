class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& arr) {
        int r = arr.size();
        int c = arr[0].size();
        
        // lower triangular matrix
        for(int i=r-2;i>=0;i--){
            int k = i+1;
            for(int j=1;j<c && k<r;){
                if(arr[k][j]==arr[k-1][j-1])
                    j++,k++;
                else
                    return false;
            }
        }
        
        // upper triangular matrix
        for(int j=1;j<=c-2;j++){
            int k = j+1;
            for(int i=1;i<r && k<c;){
                if(arr[i][k]==arr[i-1][k-1])
                    i++,k++;
                else
                    return false;
            }
        }
        return true;
    }
};

// second method
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        
        for(int r=0;r<row;r++){
            for(int c=0;c<col;c++){
                if(r>0 && c>0 && arr[r][c]!=arr[r-1][c-1]){
                    return false;   
                }
            }
        }
        return true;
    }
};