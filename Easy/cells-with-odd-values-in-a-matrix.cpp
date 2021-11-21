// first solution
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<vector<int>> arr(m,vector<int>(n,0));
        
        for(auto temp : indices){
            int r = temp[0];
            for(int i=0;i<n;i++)
                arr[r][i]++;
            int c = temp[1];
            for(int i=0;i<m;i++)
                arr[i][c]++;
        }
        
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(arr[i][j]%2==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// second solution tc : O(m+n) sc : O(m+n)
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(auto temp : indices){
            row[temp[0]] = row[temp[0]]^1;
            col[temp[1]] = col[temp[1]]^1;
        }
        
        int cnt = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(row[i]^col[j]==1){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};

// third method
class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        vector<int>row(m,0);
        vector<int>col(n,0);
        for(auto temp : indices){
            row[temp[0]] = row[temp[0]]^1;
            col[temp[1]] = col[temp[1]]^1;
        }
        
        int oddRow = 0;
        int evenRow = 0;
        for(int i=0;i<m;i++){ // for row
            if(row[i]==1)
                oddRow++;
            else
                evenRow++;
        }
        
        int oddCol = 0;
        int evenCol = 0;
        for(int i=0;i<n;i++){ // for col
            if(col[i]==1)
                oddCol++;
            else
                evenCol++;
        }
        // these combinations will generate odd numbers
        return oddRow*evenCol+evenRow*oddCol;
    }
};