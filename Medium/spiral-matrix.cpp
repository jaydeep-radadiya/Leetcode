class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& arr) {
        int row = arr.size();
        int col = arr[0].size();
        vector<int> ans;
        
        int tr = 0;
        int br = row-1;
        int lc = 0;
        int rc = col-1;
        int x = row*col;
        
        while(x>0){
            // go right
            for(int i=tr,j=lc;j<=rc && x>0;j++,x--)
                ans.push_back(arr[i][j]);
            tr++;
            
            // go down
            for(int i=tr,j=rc;i<=br && x>0;i++,x--)
                ans.push_back(arr[i][j]);
            rc--;
            
            // go left
            for(int i=br,j=rc;j>=lc && x>0;j--,x--)
                ans.push_back(arr[i][j]);
            br--;
            
            // go up
            for(int i=br,j=lc;i>=tr && x>0;i--,x--)
                ans.push_back(arr[i][j]);
            lc++;
        }
        return ans;
    }
};