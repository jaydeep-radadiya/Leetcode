// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr;
        
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                arr.push_back(nums[i]);
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]%2==1){
                arr.push_back(nums[i]);
            }
        }
        return arr;
    }
};

// using comparator
// tc : O(nlogn) cs : O(1)
class Solution {
public:
    bool static comp(int a,int b){
        if(a%2==0 && b%2==1)
            return true;
        else
            return false;
    }
    
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),comp);
        return nums;
    }
};

// inplace
// two pointer approach
// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = n-1;
        
        while(i<j){
            if(nums[i]%2==0) i++;
            else if(nums[i]%2==1){
                swap(nums[i],nums[j]);
                j--;
            }
            else if(nums[j]%2==1)
                j--;
        }
        return nums;
    }
};

// simple
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        for(int i=0,j=0;j<n;j++){
            if(nums[j]%2==0) swap(nums[i++],nums[j]);
        }
        return nums;
    }
};