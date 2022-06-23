class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        auto it = unique(nums.begin(),nums.end());
        nums.resize(it-nums.begin());
        if(nums.size()<=2) return nums[nums.size()-1];
        else return nums[nums.size()-3];
    }
};

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ele = nums[n-1];
        int uniq = 1;
        for(int i=n-2;i>=0;i--){
            if(nums[i]!=ele){
                uniq++;
                ele = nums[i];
                if(uniq==3) return nums[i];
            }
        }
        return nums[n-1];
    }
};