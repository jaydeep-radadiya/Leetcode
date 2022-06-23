class Solution {
public:
    vector<int> merge(vector<int> &arr1,vector<int> &arr2){
        vector<int> temp;
        int n1 = arr1.size();
        int n2 = arr2.size();
        int i = 0;
        int j = 0;
        
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j])
                temp.push_back(arr1[i++]);
            else
                temp.push_back(arr2[j++]);
        }
        while(i<n1)
            temp.push_back(arr1[i++]);
        while(j<n2)
            temp.push_back(arr2[j++]);
        return temp;
    }
    
    double findMedianSortedArrays(vector<int>& arr1, vector<int>& arr2) {
        vector<int> temp = merge(arr1,arr2);
        int n = temp.size();
        if(n%2==1)
            return temp[n/2];
        else
            return (temp[n/2-1]+temp[n/2])/2.0;
    }
};