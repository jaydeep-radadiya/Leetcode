class Solution {
public:
    vector<int> rearrangeArray(vector<int>& arr) {
        int n = arr.size();
        vector<int> positive,negative;
        for(int i=0;i<n;i++){
            if(arr[i]>0) positive.push_back(arr[i]);
            else negative.push_back(arr[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<positive.size();i++){
            ans.push_back(positive[i]);
            ans.push_back(negative[i]);
        }
        return ans;
    }
};