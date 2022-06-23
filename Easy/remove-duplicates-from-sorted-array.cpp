// first method
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0 or n==1) return n;
        
        vector<int> temp;
        temp.push_back(nums[0]);
        
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                temp.push_back(nums[i]);
            }
        }
        
        for(int i=0;i<temp.size();i++){
            nums[i] = temp[i];
        }
        return temp.size();
    }
};

// second method
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if(n==0 or n==1) return n;
        
        int i = 0;
        int j = 1;
        while(j<n){
            if(nums[i]==nums[j])
                j++;
            else
                nums[++i] = nums[j++];
        }
        return i+1;
    }
};