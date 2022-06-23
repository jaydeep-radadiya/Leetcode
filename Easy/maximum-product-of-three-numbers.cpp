// brute force tc : O(n^3)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        int ans = INT_MIN;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                for(int k=j+1;k<n;k++){
                    ans = max(ans,nums[i]*nums[j]*nums[k]);
                }
            }
        }
        return ans;
    }
};

// sorting tc : O(nlogn)
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int val1 = nums[n-1]*nums[n-2]*nums[n-3];
        int val2 = nums[0]*nums[1]*nums[n-1];
        if(val1>=val2)
            return val1;
        else
            return val2;
    }
};

// we need not necessarily sort the given array to find the max product 
// instead find 2 smallest values && 3 largest values
// tc : O(n)

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int max1,max2,max3;
        int min1,min2;
        max1 = max2 = max3 = INT_MIN;
        min1 = min2 = INT_MAX;
        
        for(int ele : nums){
            if(ele>=max1){
                max3 = max2;
                max2 = max1;
                max1 = ele;
            }
            else if(ele>=max2){
                max3 = max2;
                max2 = ele;
            }
            else if(ele>=max3){
                max3 = ele;
            }
            if(ele<=min1){
                min2 = min1;
                min1 = ele;
            }
            else if(ele<=min2){
                min2 = ele;
            }
        }
        return max(min1*min2*max1,max1*max2*max3);
    }
};