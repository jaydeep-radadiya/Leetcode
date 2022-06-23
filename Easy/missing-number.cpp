class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int total = 0;
        for(int temp : nums){
            total += temp;
        }
        return sum-total;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        vector<bool> present(n+1,false);
        for(int temp : nums){
            present[temp] = true;
        }
        
        for(int i=0;i<=n;i++){
            if(present[i]==false){
                return i;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        
        int val = 0;
        for(int temp : nums){
            val = val^temp;
        }
        
        for(int i=0;i<=n;i++){
            val = val^i;
        }
        return val;
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(i!=nums[i]){
                return i;
            }
        }
        return n;
    }
};