class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ss;
        for(int i=0;i<n;i++)
            ss.insert(nums[i]);
        
        for(int i=1;i<=n;i++){
            if(ss.find(i)==ss.end()){
                return i;
            }
        }
        return n+1;
    }
};