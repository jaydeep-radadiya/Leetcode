// similar to book allocation problem
// tc : O(n*log(sum-max))

class Solution {
public:
    // number of sub arrays by keeping the limit
    bool is_valid(vector<int> &nums,int limit,int m){
        int cnt = 1;
        int i = 0;
        int sum = 0;
        
        while(i<nums.size()){
            if(sum+nums[i]>limit){
                sum = 0;
                cnt++;
            }
            sum += nums[i];
            i++;
        }
        if(cnt<=m) return true;
        else return false;
    }
    
    int splitArray(vector<int>& nums, int m) {
        int left = *max_element(nums.begin(),nums.end());
        int right = accumulate(nums.begin(),nums.end(),0);
        
        while(left<right){
            int mid = left+(right-left)/2;
            if(is_valid(nums,mid,m))
                right = mid;
            else
                left = mid+1;
        }
        return right;
    }
};