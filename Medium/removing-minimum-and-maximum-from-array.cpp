// tc : O(n) sc : O(1)
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n==1 || n==2) return n;
        
        int mnIdx = min_element(nums.begin(),nums.end())-nums.begin();
        int mxIdx = max_element(nums.begin(),nums.end())-nums.begin();
        if(mnIdx>mxIdx) swap(mnIdx,mxIdx);
        return min({mnIdx+1+n-mxIdx,n-mnIdx,mxIdx+1});
    }
};