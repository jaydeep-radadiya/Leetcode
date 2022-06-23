class Solution {
public:
    int firstIndex(vector<int> &nums,int target){
        int n = nums.size();
        int idx = lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(idx<n and nums[idx]==target)
            return idx;
        else
            return -1;
    }
    
    int lastIndex(vector<int> &nums,int target){
        int n = nums.size();
        int idx = upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        idx--;
        if(idx>=0 and nums[idx]==target)
            return idx;
        else
            return -1;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        int first = firstIndex(nums,target);
        if(first==-1) return {-1,-1};
        
        int last = lastIndex(nums,target);
        return {first,last};
    }
};