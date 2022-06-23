// brute force TLE
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> ans;
        
        for(int i=0;i<=n-k;i++){
            int mx_ele = INT_MIN;
            for(int j=i;j<i+k;j++){
                mx_ele = max(mx_ele,arr[j]);
            }
            ans.push_back(mx_ele);
        }
        return ans;
    }
};

// sliding window
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& arr, int k) {
        int n = arr.size();
        map<int,int> mp;
        vector<int> ans;
        int i = 0;
        int j = 0;
        
        while(j<n){
            mp[arr[j]]++;
            if(j-i+1<k){
                j++;
            }
            else{
                ans.push_back(mp.rbegin()->first);
                mp[arr[i]]--;
                if(mp[arr[i]]==0) mp.erase(arr[i]);
                i++;
                j++;
            }
        }
        return ans;        
    }
};