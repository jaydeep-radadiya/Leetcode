class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ss;
        for(int i=0;i<n;i++){
            int cnt = 0;
            for(int j=0;j<n;j++){
                if(nums[i]==nums[j]){
                    cnt++;
                }
            }
            if(cnt>n/3){
                ss.insert(nums[i]);
            }
        }
        
        vector<int> ans;
        for(auto it : ss){
            ans.push_back(it);
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }
        
        vector<int> ans;
        for(auto it : ump){
            if(it.second>n/3){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

// at max you have 2 majority element (striver solution)
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int sz = nums.size();
        
        int n1 = -1;
        int n2 = -1;
        int cnt1 = 0;
        int cnt2 = 0;
        for(int i=0;i<sz;i++){
            if(nums[i]==n1)
                cnt1++;
            else if(nums[i]==n2)
                cnt2++;
            else if(cnt1==0){
                n1 = nums[i];
                cnt1++;
            }
            else if(cnt2==0){
                n2 = nums[i];
                cnt2++;
            }
            else{
                cnt1--;
                cnt2--;
            }
        }
        
        cnt1 = cnt2 = 0;
        for(int num : nums){
            if(num==n1) cnt1++;
            else if(num==n2) cnt2++;
        }
        
        vector<int> ans;
        if(cnt1>sz/3) ans.push_back(n1);
        if(cnt2>sz/3) ans.push_back(n2);
        return ans;
    }
};