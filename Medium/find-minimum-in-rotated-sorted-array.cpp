// brute force
class Solution {
public:
    int findMin(vector<int>& nums) {
        return *min_element(nums.begin(),nums.end());
    }
};

class Solution {
public:
    int solve(vector<int> &nums,int n){
        int left = 0;
        int right = n-1;
        
        while(left<=right){
            if(nums[left]<=nums[right])
                return left;
            
            int mid = left+(right-left)/2;
            int prev = (mid-1+n)%n;
            int next = (mid+1)%n;
            
            if(nums[prev]>=nums[mid] && nums[next]>=nums[mid])
                return mid;
            else if(nums[left]<=nums[mid])
                left = mid+1;
            else if(nums[mid]<=nums[right])
                right = mid-1;
        }
        return -1;
    }
    
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int idx = solve(nums,n);
        return nums[idx];
    }
};

// striver method
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(nums[mid]<nums[right])
                right = mid;
            else // nums[mid]>nums[right]
                left = mid+1;
        }
        return nums[left];
    }
};