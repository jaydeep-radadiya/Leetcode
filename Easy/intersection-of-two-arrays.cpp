// tc : O(n*m) sc : O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        unordered_set<int> ss;
        
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                if(arr1[i]==arr2[j]){
                    ss.insert(arr1[i]);
                }
            }
        }
        
        vector<int> ans;
        for(auto ele : ss){
            ans.push_back(ele);
        }
        return ans;
    }
};

// tc : O(mlogn) sc : O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        sort(arr2.begin(),arr2.end());
        
        unordered_set<int> ss;
        for(int ele : arr1){
            if(binary_search(arr2.begin(),arr2.end(),ele)){
                ss.insert(ele);   
            }
        }
        
        vector<int> ans;
        for(int ele : ss){
            ans.push_back(ele);
        }
        return ans;
    }
};

// tc : O(n) sc : O(n)
class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        unordered_set<int> ss;
        for(int i=0;i<n1;i++)
            ss.insert(arr1[i]);
        
        vector<int> ans;
        for(int i=0;i<n2;i++){
            if(ss.find(arr2[i])!=ss.end()){
                ans.push_back(arr2[i]);
                ss.erase(arr2[i]);
            }
        }
        return ans;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    vector<int> intersection(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
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
                while(i<n1 && arr1[i]==v1) i++;
                while(j<n2 && arr2[j]==v2) j++;
            }
            else if(v1>v2)
                j++;
            else
                i++;
        }
        return ans;
    }
};