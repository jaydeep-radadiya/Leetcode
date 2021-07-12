class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> ans;
        sort(arr.begin(),arr.end());
        
        int mn = INT_MAX;
        for(int i=1;i<arr.size();i++){
            mn = min(mn,arr[i]-arr[i-1]);
        }
        
        for(int i=1;i<arr.size();i++){
            if(arr[i]-arr[i-1]==mn){
                vector<int> v{arr[i-1],arr[i]};
                ans.push_back(v);
            }
        }
        
        return ans;
    }
};