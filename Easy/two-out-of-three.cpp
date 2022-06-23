class Solution {
private:
    vector<int> helper(vector<int> &arr){
        sort(arr.begin(),arr.end());
        auto it = unique(arr.begin(),arr.end());
        arr.resize(it-arr.begin());
        return arr;
    }
    
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        nums1 = helper(nums1);
        nums2 = helper(nums2);
        nums3 = helper(nums3);
        
        unordered_map<int,int> ump;
        for(int i=0;i<nums1.size();i++)
            ump[nums1[i]]++;
        for(int i=0;i<nums2.size();i++)
            ump[nums2[i]]++;
        for(int i=0;i<nums3.size();i++)
            ump[nums3[i]]++;
        
        vector<int> ans;
        for(auto &t : ump){
            if(t.second>=2){
                ans.push_back(t.first);
            }
        }
        return ans;
    }
};