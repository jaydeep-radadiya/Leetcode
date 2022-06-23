class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int sum = 0;
        
        for(int i=0,j=0;i<n;i++)
            sum += arr[i][j++];
        
        for(int j=n-1,i=0;j>=0;j--)
            sum += arr[i++][j];
        
        if(n%2==1)
            return sum-arr[n/2][n/2];
        else
            return sum;
    }
};

// better way to write
class Solution {
public:
    int diagonalSum(vector<vector<int>>& arr) {
        int n = arr.size();
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i][i]+arr[i][n-i-1];
        }
        if(n%2==1){
            sum -= arr[n/2][n/2];
        }
        return sum;
    }
};