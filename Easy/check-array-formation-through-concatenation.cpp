// first
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,int> ump;
        for(int i=0;i<arr.size();i++){
            ump[arr[i]] = i; // val -> idx
        }
        
        for(auto nums : pieces){
            int val = nums[0];
            if(ump.find(val)==ump.end()) return false;
            int i = ump[val];
            int j = 0; // of 2d matrix
            while(j<nums.size() and i<arr.size()){
                if(nums[j]!=arr[i]) return false;
                i++;
                j++;
            }
            if(j!=nums.size()) return false;
        }
        return true;
    }
};

// second
class Solution {
public:
    bool canFormArray(vector<int>& arr, vector<vector<int>>& pieces) {
        unordered_map<int,vector<int>> ump;
        for(auto nums : pieces){
            ump[nums[0]] = nums;
        }
        
        vector<int> ans;
        for(int i=0;i<arr.size();i++){
            if(ump.find(arr[i])!=ump.end()){
                for(int temp : ump[arr[i]]){
                    ans.push_back(temp);
                }
            }
        }
        return ans==arr;
    }
};