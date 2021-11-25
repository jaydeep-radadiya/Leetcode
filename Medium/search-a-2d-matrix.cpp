// brute force 
// tc : O(r*c) cs : O(1)
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

// tc : O(r+c)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int r = arr.size();
        int c = arr[0].size();
        
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

// apply bs on index
// tc : O(log(r*c)) sc : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        int r = arr.size();
        int c = arr[0].size();
        
        int left = 0;
        int right = r*c-1;
        while(left<=right){
            int mid = left+(right-left)/2;
            
            int val = arr[mid/c][mid%c];
            if(val==target)
                return true;
            else if(val>target)
                right = mid-1;
            else if(val<target)
                left = mid+1;
        }
        return false;
    }
};

// another method
// store all elements in temp array
// then apply bs

// apply bs on every row
// tc : O(r*logc) sc : O(1)
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& arr, int target) {
        for(auto row : arr){
            bool ans = binary_search(row.begin(),row.end(),target);
            if(ans==true) return true;
        }
        return false;
    }
};