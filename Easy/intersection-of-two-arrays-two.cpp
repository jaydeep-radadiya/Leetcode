// tc : O(m+n) sc : O(m+n)
class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        unordered_map<int,pair<int,int>> ump;
        for(int i=0;i<n1;i++)
            ump[arr1[i]].first++;
        for(int i=0;i<n2;i++)
            ump[arr2[i]].second++;
        
        vector<int> ans;
        for(auto &t : ump){
            int val = t.first;
            int freq = min(t.second.first,t.second.second);
            while(freq--){
                ans.push_back(val);
            }
        }
        return ans;
    }
};

// tc : O(nlogn) sc : O(1)
class Solution {
public:
    vector<int> intersect(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        // given array is already sorted
        sort(arr1.begin(),arr1.end());
        sort(arr2.begin(),arr2.end());
        vector<int> ans;
        
        int i = 0;
        int j = 0;
        while(i<n1 && j<n2){
            int v1 = arr1[i];
            int v2 = arr2[j];
            if(v1==v2){
                ans.push_back(v1);
                i++;
                j++;
            }
            else if(v1>v2)
                j++;
            else
                i++;
        }
        return ans;
    }
};