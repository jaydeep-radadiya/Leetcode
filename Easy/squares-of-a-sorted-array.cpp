// tc : O(nlogn) sc : O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++)
            ans.push_back(nums[i]*nums[i]);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// inplace
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for(int &ele : nums)
            ele = ele*ele;
        sort(nums.begin(),nums.end());
        return nums;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int l = 0;
        int r = n-1;
        
        while(l<=r){
            if(nums[l]*nums[l]>=nums[r]*nums[r]){
                ans.push_back(nums[l]*nums[l]);
                l++;
            }
            else{
                ans.push_back(nums[r]*nums[r]);
                r--;
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        int idx = lower_bound(nums.begin(),nums.end(),0)-nums.begin(); // positive val idx
        vector<int> ans(n);
        
        int i = idx; // -->
        int j = idx-1; // <--
        int k = 0;
        while(i<n && j>=0){
            if(nums[j]*nums[j]>=nums[i]*nums[i]){
                ans[k++] = nums[i]*nums[i];
                i++;
            }
            else{
                ans[k++] = nums[j]*nums[j];
                j--;
            }
        }
        while(i<n){
            ans[k++] = nums[i]*nums[i];
            i++;
        }
        while(j>=0){
            ans[k++] = nums[j]*nums[j];
            j--;
        }
        return ans;
    }
};