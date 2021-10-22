// first method
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        
        for(int i=0;i<nums.size();i++)
            ump[nums[i]]++;
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;
        for(auto it=ump.begin();it!=ump.end();it++){
            minh.push({it->second,it->first});
            if(minh.size()>k)
                minh.pop();
        }
        
        vector<int> ans;
        while(not minh.empty()){
            int ele = minh.top().second;
            ans.push_back(ele);
            minh.pop();
        }
        
        return ans;
    }
};

// second method
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> ump;
        
        for(int i=0;i<nums.size();i++)
            ump[nums[i]]++;
        
        vector<pair<int,int>> temp;
        for(auto it=ump.begin();it!=ump.end();it++){
            temp.push_back({it->second,it->first});
        }
        sort(temp.begin(),temp.end(),greater<pair<int,int>>());
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(temp[i].second);
        }
        
        return ans;
    }
};