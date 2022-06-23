// tc : O(n) cs : O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        for(int i=1;i<n-1;i++){
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]){
                return i;
            }
        }
        return -1;
    }
};

// tc : O(n) cs : O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int idx = -1;
        int mx_val = INT_MIN;
        for(int i=0;i<n;i++){
            if(nums[i]>mx_val){
                mx_val = nums[i];
                idx = i;
            }
        }
        return idx;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int idx = max_element(nums.begin(),nums.end())-nums.begin();
        return idx;
    }
};

// binary search
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(nums[mid]>nums[mid+1])
                right = mid; // we don't want to loose our answer
            else
                left = mid+1;
        }
        return left;
    }
};

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& nums) {
        int i = 0;
        while(nums[i]<nums[i+1]){
            i++;
        }
        return i;
    }
};