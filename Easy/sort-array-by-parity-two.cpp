class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> odd;
        vector<int> even;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0)
                even.push_back(nums[i]);
            else
                odd.push_back(nums[i]);
        }
        
        for(int i=0;i<n;i++){
            if(i%2==0){
                nums[i] = even.back();
                even.pop_back();
            }
            else{
                nums[i] = odd.back();
                odd.pop_back();
            }
        }
        return nums;
    }
};

// tc : O(n) cs : O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);
        
        int even = 0;
        int odd = 1;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                arr[even] = nums[i];
                even += 2;
            }
            else{
                arr[odd] = nums[i];
                odd += 2;
            }
        }
        return arr;
    }
};

// optimised : inplace
// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        
        while(i<n && j<n){
            while(i<n && nums[i]%2==0)
                i += 2;
            while(j<n && nums[j]%2==1)
                j += 2;
            if(i<n && j<n)
                swap(nums[i],nums[j]);
        }
        return nums;
    }
};