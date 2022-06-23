class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        
        for(int i=0;i<arr.size()-1;i++){
            int mx = arr[i+1];
            for(int j=i+1;j<arr.size();j++){
                mx = max(mx,arr[j]);
            }
            ans.push_back(mx);
        }
        ans.push_back(-1);
        return ans;
    }
};

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        vector<int> ans;
        
        for(int i=0;i<arr.size()-1;i++){
            int mx = *max_element(arr.begin()+i+1,arr.end());
            ans.push_back(mx);
        }
        ans.push_back(-1);
        return ans;
    }
};

class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,-1);
        
        int mx_val = -1;
        for(int i=n-1;i>=0;i--){
            ans[i] = mx_val;
            mx_val = max(mx_val,arr[i]);
        }
        return ans;
    }
};