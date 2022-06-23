class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size();
        int idx = max_element(arr.begin(),arr.end())-arr.begin();
        if(n<3 or idx==0 or idx==n-1) return false;
        
        for(int i=1;i<=idx;i++){
            if(arr[i-1]<arr[i]) continue;
            else return false;
        }
        for(int i=n-2;i>=idx;i--){
            if(arr[i]>arr[i+1]) continue;
            else return false;
        }
        return true;
    }
};

// single pass
class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        int n = arr.size(), i = 0, j = n-1;
        while(i+1<n && arr[i]<arr[i+1]) i++;
        while(j>0 && arr[j]<arr[j-1]) j--;
        return i>0 && j<n-1 && i==j;
    }
};