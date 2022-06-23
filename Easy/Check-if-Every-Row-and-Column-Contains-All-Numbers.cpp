class Solution {
public:
    bool checkValid(vector<vector<int>>& arr) {
        int n = arr.size();
        int val = 0;
        for(int i=1;i<=n;i++){
            val = val^i;
        }
        
        for(int i=0;i<n;i++){
            int temp = 0;
            for(int j=0;j<n;j++){
                temp = temp^arr[i][j];
            }
            if(temp!=val) return false;
        }
        
        for(int j=0;j<n;j++){
            int temp = 0;
            for(int i=0;i<n;i++){
                temp = temp^arr[i][j];
            }
            if(temp!=val) return false;
        }
        return true;
    }
};