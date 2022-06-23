class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++)
            ump[nums[i]]++;
        
        vector<int> arr;
        for(auto it=ump.begin();it!=ump.end();it++)
            arr.push_back(it->first);
        
        sort(arr.begin(),arr.end(),greater<int>());
        arr.pop_back();
        
        int cnt = 0;
        int temp = 0;
        for(int i=0;i<arr.size();i++){
            temp += ump[arr[i]];
            cnt += temp;
        }
        return cnt;
    }
};