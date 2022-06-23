class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++)
            ump[nums[i]]++;
        
        vector<int> ans;
        for(auto temp : ump){
            if(temp.second==1){
                ans.push_back(temp.first);
            }
        }
        return ans;
    }
};