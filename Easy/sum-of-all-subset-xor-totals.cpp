// tc : O(n*2^n) sc : O(1)
class Solution {
public:
    int filterVal(vector<int> &nums,int n){
        int i = 0;
        int temp = 0;
        while(n>0){
            if(n&1){
                temp = temp^nums[i];
            }
            i++;
            n = n>>1;
        }
        return temp;
    }
    
    int generateSubsets(vector<int> &nums,int n){
        int len = 1<<n;
        int sum = 0;
        for(int i=0;i<len;i++){
            sum += filterVal(nums,i);
        }
        return sum;
    }
    
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return generateSubsets(nums,n);
    }
};

// second solution
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++){
            res = res|nums[i];
        }
        return res*(1<<n-1);
    }
};

// same as second solution
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        return accumulate(nums.begin(),nums.end(),0,bit_or<int>())<<(n-1);
    }
};