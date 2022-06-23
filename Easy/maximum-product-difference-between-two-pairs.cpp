class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-1]*nums[n-2]-nums[0]*nums[1];
    }
};

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        
        for(int val : nums){
            if(val>max1){
                max2 = max1;
                max1 = val;
            }
            else if(val>max2){
                max2 = val;
            }
            if(val<min1){
                min2 = min1;
                min1 = val;
            }
            else if(val<min2){
                min2 = val;
            }
        }
        return (max1*max2)-(min1*min2);
    }
};