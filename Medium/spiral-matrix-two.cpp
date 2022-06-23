class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> arr(n,vector<int>(n,0));
        int x = 1;
        int tr = 0;
        int br = n-1;
        int lc = 0;
        int rc = n-1;
        
        while(x<=n*n){
            // fill top row
            for(int i=tr,j=lc;j<=rc;j++)
                arr[i][j] = x++;
            tr++;
                
            // fill right col
            for(int i=tr,j=rc;i<=br;i++)
                arr[i][j] = x++;
            rc--;
            
            // fill bottom row
            for(int i=br,j=rc;j>=lc;j--)
                arr[i][j] = x++;
            br--;
            
            // fill left col
            for(int i=br,j=lc;i>=tr;i--)
                arr[i][j] = x++;
            lc++;
        }
        return arr;
    }
};