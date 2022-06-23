class Solution {
public:
    vector<int> getRow(int rowIdx) {
        vector<vector<int>> arr;
        for(int i=1;i<=rowIdx+1;i++){
            vector<int> temp(i,1);
            arr.push_back(temp);
        }
        
        for(int i=2;i<=rowIdx;i++){
            for(int j=1;j<i;j++){
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            }
        }
        return arr[rowIdx];
    }
};

// sc : O(k)
class Solution {
public:
    vector<int> getRow(int rowIdx) {
        vector<int> arr(rowIdx+1);
        arr[0] = 1;
        
        for(int i=0;i<=rowIdx;i++){
            for(int j=i;j>0;j--){
                arr[j] = arr[j]+arr[j-1];
            }
        }
        return arr;
    }
};