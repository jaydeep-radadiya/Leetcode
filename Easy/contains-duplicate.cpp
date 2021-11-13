class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
            if(ump[nums[i]]>=2){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                return true;
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> ss;
        
        for(int i=0;i<nums.size();i++){
            ss.insert(nums[i]);
        }
        
        return not (ss.size()==nums.size());
    }
};

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        return set<int>(nums.begin(),nums.end()).size() < nums.size();
    }
};