class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> arr;
        arr.push_back(first);
        int temp = first;
        
        for(int i=0;i<n;i++){
            temp = temp^encoded[i];
            arr.push_back(temp);    
        }
        return arr;
    }
};