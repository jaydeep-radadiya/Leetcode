class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int cnt = 0;
        
        for(int ele : nums){
            if(ele==1)
                mx = max(mx,++cnt);
            else
                cnt = 0;
        }
        return mx;
    }
};

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();
        int mx = 0;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            if(nums[i]==0)
                sum = 0;
            else
                mx = max(mx,sum);
        }
        return mx;
    }
};