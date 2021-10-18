// first method
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx_sum = nums[0];
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int sum = 0;
                for(int k=i;k<=j;k++){
                    sum += nums[k];
                }
                mx_sum = max(mx_sum,sum);
            }
        }
        return mx_sum;
    }
};

// second method
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx_sum = nums[0];
        
        for(int i=0;i<n;i++){
            int sum = 0;
            for(int j=i;j<n;j++){
                sum += nums[j];
                mx_sum = max(mx_sum,sum);
            }
        }
        return mx_sum;
    }
};

// third method
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mx_sum = nums[0];
        int temp = 0;
        
        for(int i=0;i<n;i++){
            temp = max(nums[i],temp+nums[i]);
            mx_sum = max(mx_sum,temp);
        }
        return mx_sum;
    }
};