// tc : O(n^2*log(n^2))
class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        vector<int> temp;
        for(int i=0;i<arr.size();i++){
            for(int j=0;j<arr[0].size();j++){
                temp.push_back(arr[i][j]);
            }
        }
        
        sort(temp.begin(),temp.end());
        return temp[k-1];
    }
};

class Solution {
public:
    int kthSmallest(vector<vector<int>>& arr, int k) {
        int n = arr.size();
        priority_queue<int> maxh;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                maxh.push(arr[i][j]);
                if(maxh.size()>k){
                    maxh.pop();
                }
            }
        }
        return maxh.top();
    }
};