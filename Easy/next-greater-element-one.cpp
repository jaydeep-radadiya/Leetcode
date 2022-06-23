// brute force
// tc : O(n^2) sc : O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        unordered_map<int,int> ump;
        stack<int> st;
        
        for(int i=0;i<n2;i++){
            bool present = false;
            for(int j=i+1;j<n2;j++){
                if(arr2[j]>arr2[i]){
                    present = true;
                    ump[arr2[i]] = arr2[j];
                    break;
                }
            }
            if(present==false){
                ump[arr2[i]] = -1;
            }
        }
        
        vector<int> ans;
        for(int i=0;i<n1;i++){
            ans.push_back(ump[arr1[i]]);
        }
        return ans;
    }
};

// tc : O(n1+n2) sc : O(n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& arr1, vector<int>& arr2) {
        int n1 = arr1.size();
        int n2 = arr2.size();
        
        unordered_map<int,int> ump;
        stack<int> st;
        for(int i=n2-1;i>=0;i--){
            while(st.size()>0 && st.top()<=arr2[i])
                st.pop();
            if(st.size()==0)
                ump[arr2[i]] = -1;
            else
                ump[arr2[i]] = st.top();
            st.push(arr2[i]);
        }
        
        vector<int> ans;
        for(int i=0;i<n1;i++){
            ans.push_back(ump[arr1[i]]);
        }
        return ans;
    }
};