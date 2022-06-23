class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        
        arr[0] = nums[0];
        for(int i=1;i<n;i++){
            arr[i] = arr[i-1]+nums[i];
        }
        return arr;
    }
};

// inplace
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int n = nums.size();

        for(int i=1;i<n;i++){
            nums[i] = nums[i-1]+nums[i];
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        partial_sum(nums.begin(),nums.end(),nums.begin());
        return nums;
    }
};