class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr(heights.begin(),heights.end());
        sort(heights.begin(),heights.end());
        
        int cnt = 0;
        int n = heights.size();
        for(int i=0;i<n;i++){
            if(arr[i]!=heights[i]){
                cnt++;
            }
        }
        return cnt;
    }
};