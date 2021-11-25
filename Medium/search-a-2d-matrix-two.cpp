// brute force
// tc : O(r*c) sc : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int r = arr.size();
        int c = arr[0].size();
        
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(arr[i][j]==target){
                    return true;
                }
            }
        }
        return false;
    }
};

// tc : O(r+c) sc : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int r = arr.size();
        int c = arr[0].size();
        
        // we can start from top right
        // we also start from bottom left

        int i = 0;
        int j = c-1;
        while(j>=0 && i<r){
            if(arr[i][j]==target)
                return true;
            else if(arr[i][j]>target)
                j--;
            else if(arr[i][j]<target)
                i++;
        }
        return false;
    }
};