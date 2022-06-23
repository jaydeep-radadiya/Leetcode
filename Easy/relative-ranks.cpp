class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        int n = nums.size();
        map<int,string> mp;
        for(int i=0;i<n;i++)
            mp[nums[i]] = "";
        
        int i = 1;
        for(auto it=mp.rbegin();it!=mp.rend();it++,i++){
            if(i==1)
                it->second = "Gold Medal";
            else if(i==2)
                it->second = "Silver Medal";
            else if(i==3)
                it->second = "Bronze Medal";
            else
                it->second = to_string(i);
        }
        
        vector<string> ans;
        for(int i=0;i<n;i++){
            ans.push_back(mp[nums[i]]);
        }
        return ans;
    }
};