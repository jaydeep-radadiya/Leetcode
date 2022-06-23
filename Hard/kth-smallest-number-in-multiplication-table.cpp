// tc : O(xlogx) where x = m*n
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        vector<int> ans;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                ans.push_back(i*j);
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans[k-1];
    }
};

// time limit exceeded
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        priority_queue<int> maxh;
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                maxh.push(i*j);
                if(maxh.size()>k){
                    maxh.pop();
                }
            }
        }
        
        return maxh.top();
    }
};

// binary search
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int left = 1;
        int right = m*n;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            // return number of elements has value <= mid
            if(helper(mid,m,n,k)<k){
                left = mid+1;
            }
            else{
                right = mid-1;
            }
        }
        return left;
    }
    
    // count the number of elements has value <= mid
    int helper(int mid,int r,int c,int k){
        int cnt = 0;
        for(int i=1;i<=r;i++){
            cnt += min(mid/i,c);
        }
        return cnt;
    }
};