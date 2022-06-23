class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int r = mat.size();
        int c = mat[0].size();
        
        for(int k=0;k<4;k++){
            vector<vector<int>> temp(r, vector<int>(c,0));
            
            for(int i1=r-1,j2=0;i1>=0 and j2<c;i1--,j2++){
                for(int j1=0,i2=0;j1<c and i2<r;j1++,i2++){
                    temp[i2][j2] = mat[i1][j1];
                }
            }
            mat = temp;
            
            if(mat==target) return true;
        }
        return false;
    }
};