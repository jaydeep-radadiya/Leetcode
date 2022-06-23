class Solution {
public:
    vector<int> findLonely(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[arr[i]]++;
        }
        
        for(int i=0;i<n;i++){
            if(ump[arr[i]]==1){
                if(ump[arr[i]-1]==0 && ump[arr[i]+1]==0){
                    ans.push_back(arr[i]);
                }
            }
        }
        return ans;
    }
};