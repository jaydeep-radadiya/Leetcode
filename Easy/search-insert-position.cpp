// first method
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        int res = n;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            
            if(nums[mid]>=target){
                res = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        return res;
    }
};

// second method
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int idx = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        return idx;
    }
};

// brute force
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]>=target){
                return i;
            }
        }
        return n;
    }
};