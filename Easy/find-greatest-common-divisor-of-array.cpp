class Solution {
public:
    int findGCD(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        return __gcd(nums[0],nums[n-1]);
    }
};

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = INT_MAX;
        int large = INT_MIN;
        for(int i=0;i<nums.size();i++){
            small = min(small,nums[i]);
            large = max(large,nums[i]);
        }
        return __gcd(small,large);
    }
};

class Solution {
public:
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin(),nums.end());
        int large = *max_element(nums.begin(),nums.end());
        return __gcd(small,large);
    }
};

class Solution {
public:
    int gcd(int a,int b){
        if(b==0) return a;
        return gcd(b,a%b);
    }
    
    int findGCD(vector<int>& nums) {
        int small = *min_element(nums.begin(),nums.end());
        int large = *max_element(nums.begin(),nums.end());
        return gcd(small,large);
    }
};