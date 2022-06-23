class Solution {
public:
    int distributeCandies(vector<int>& arr) {
        int n = arr.size();
        int k = n/2;
        unordered_set<int> ss;
        
        for(int i=0;i<n && k>0;i++){
            if(ss.find(arr[i])==ss.end()){
                ss.insert(arr[i]);
                k--;
            }
        }
        return ss.size();
    }
};

class Solution {
public:
    int distributeCandies(vector<int>& arr) {
        int n1 = arr.size();
        sort(arr.begin(),arr.end());
        auto it = unique(arr.begin(),arr.end());
        arr.resize(it-arr.begin());

        int n2 = arr.size();
        return min(n1/2,n2);
    }
};