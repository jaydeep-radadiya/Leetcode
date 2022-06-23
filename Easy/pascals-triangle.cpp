class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> arr;
        for(int i=1;i<=n;i++){
            vector<int> temp(i,1);
            arr.push_back(temp);
        }
        
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            }
        }
        return arr;
    }
};