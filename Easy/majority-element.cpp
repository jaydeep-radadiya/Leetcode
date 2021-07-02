class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int idx_mjr = 0;
        int cnt = 1;
        
        for(int i=1;i<n;i++){
            if(nums[i]==nums[idx_mjr])
                cnt++;
            else
                cnt--;
            
            if(cnt==0){
                idx_mjr = i;
                cnt = 1;
            }
        }
        
        if(count(nums.begin(),nums.end(),nums[idx_mjr])>n/2)
            return nums[idx_mjr];
        else
            return -1;
    }
};