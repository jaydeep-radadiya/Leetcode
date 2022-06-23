class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int n = nums.size();
        int idx = max_element(nums.begin(),nums.end())-nums.begin();
        int mx = nums[idx];
        
        for(int i=0;i<n;i++){
            if(i==idx) continue;
            if(mx<2*nums[i]){
                return -1;
            }
        }
        return idx;
    }
};