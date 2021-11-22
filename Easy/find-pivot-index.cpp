// brute force tle
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            int left = 0;
            for(int j=0;j<i;j++)
                left += nums[j];
            int right = 0;
            for(int j=i+1;j<n;j++)
                right += nums[j];
            if(left==right)
                return i;
        }
        return -1;
    }
};

// accepted
// tc : O(n) sc : O(n)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> left(n,0);
        left[0] = nums[0];
        for(int i=1;i<n;i++)
            left[i] = left[i-1]+nums[i];
        
        vector<int> right(n,0);
        right[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
            right[i] = right[i+1]+nums[i];
        
        for(int i=0;i<n;i++){
            if(left[i]==right[i]){
                return i;
            }
        }
        return -1;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int leftSum = 0;
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        for(int i=0;i<n;i++){
            rightSum -= nums[i];
            if(leftSum==rightSum){
                return i;
            }
            leftSum += nums[i];
        }
        return -1;
    }
};