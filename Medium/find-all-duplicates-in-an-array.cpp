// time limit exceed
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j]){
                    ans.push_back(nums[i]);
                    break;
                }
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> freq(n+1,0);
        for(int i=0;i<n;i++){
            freq[nums[i]]++;    
        }
        
        vector<int> ans;
        for(int i=1;i<=n;i++){
            if(freq[i]==2){
                ans.push_back(i);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
        }
        
        vector<int> ans;
        for(auto it : ump){
            if(it.second==2){
                ans.push_back(it.first);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> ss;
        vector<int> ans;
        for(int i=0;i<n;i++){
            int ps = ss.size(); // previous size
            ss.insert(nums[i]);
            int as = ss.size(); // after size
            if(ps==as){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<int> ans;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// note : if i subtract 1 from input array then it's valid index
// negation if index
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            int idx = abs(nums[i])-1;
            if(nums[idx]<0)
                ans.push_back(idx+1);
            else
                nums[idx] = -nums[idx];
        }
        return ans;
    }
};