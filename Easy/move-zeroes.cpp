// first
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                cnt++;
            }
        }
        
        vector<int> temp;
        for(int ele : nums){
            if(ele!=0){
                temp.push_back(ele);
            }
        }
        
        while(cnt--){
            temp.push_back(0);
        }
        
        for(int i=0;i<n;i++){
            nums[i] = temp[i];
        }
    }
};

// second
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        vector<int> temp;
        int cnt = 0;
        for(int i=0;i<n;i++){
            if(nums[i]==0)
                cnt++;
            else
                temp.push_back(nums[i]);
        }
        
        int i = 0;
        for(i=0;i<temp.size();i++)
            nums[i] = temp[i];
        for(;i<n;i++)
            nums[i] = 0;
    }
};

// third
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int idx = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0){
                nums[idx++] = nums[i];
            }
        }
        
        for(int i=idx;i<nums.size();i++){
            nums[i] = 0;
        }
    }
};