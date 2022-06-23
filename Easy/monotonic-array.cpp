class Solution {
public:
    bool monoinc(vector<int> &nums){
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]>nums[i]){
                return false;
            }
        }
        return true;
    }
    
    bool monodec(vector<int> &nums){
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i-1]<nums[i]){
                return false;
            }
        }
        return true;
    }
    
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        if(n==0 || n==1) return true;
        
        if(nums[0]<=nums[n-1])
            return monoinc(nums);
        else
            return monodec(nums);
    }
};