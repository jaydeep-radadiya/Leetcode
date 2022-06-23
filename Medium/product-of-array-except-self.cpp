// brute force tc : O(n^2)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int pro = 1;
            for(int j=0;j<n;j++){
                if(i!=j){
                    pro = pro*arr[j];
                }
            }
            ans.push_back(pro);
        }
        return ans;
    }
};

// tc : O(n) sc : O(n)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        vector<int> ans;
        
        for(int i=1;i<n;i++)
            left[i] = left[i-1]*arr[i-1];
        
        for(int i=n-2;i>=0;i--)
            right[i] = right[i+1]*arr[i+1];
        
        for(int i=0;i<n;i++)
            ans.push_back(left[i]*right[i]);
        return ans;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,1);
        
        int temp = 1;
        for(int i=0;i<n;i++){
            ans[i] = temp;
            temp = temp*arr[i];
        }
        
        temp = 1;
        for(int i=n-1;i>=0;i--){
            ans[i] = ans[i]*temp;
            temp = temp*arr[i];
        }
        return ans;
    }
};