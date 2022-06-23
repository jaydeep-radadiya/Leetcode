class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        unordered_map<string,vector<string>> ump;
        for(int i=0;i<arr.size();i++){
            string original = arr[i];
            sort(arr[i].begin(),arr[i].end());
            ump[arr[i]].push_back(original);
        }
        
        vector<vector<string>> ans;
        for(auto &it : ump){
            ans.push_back(it.second);
        }
        return ans;
    }
};