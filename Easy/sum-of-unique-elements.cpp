class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> ump;
        for(int i=0;i<nums.size();i++)
            ump[nums[i]]++;
        
        int sum = 0;
        for(auto it : ump){
            if(it.second==1){
                sum += it.first;
            }
        }
        return sum;
    }
};