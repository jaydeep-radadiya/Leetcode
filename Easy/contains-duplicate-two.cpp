// bruteforce TLE
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n = nums.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i]==nums[j] and abs(j-i)<=k){
                    return true;
                }
            }
        }
        return false;
    }
};

// accepted
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,vector<int>> ump;
        
        for(int i=0;i<n;i++){
            ump[arr[i]].push_back(i);
        }
        
        for(auto &it : ump){
            vector<int> &temp = it.second;
            for(int i=1;i<temp.size();i++){
                if(abs(temp[i]-temp[i-1])<=k){
                    return true;
                }
            }
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            if(ump.find(arr[i])!=ump.end() && i-ump[arr[i]]<=k){
                return true;
            }
            ump[arr[i]] = i;
        }
        return false;
    }
};

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_set<int> ss;
        for(int i=0;i<n;i++){
            if(i>k){
                ss.erase(arr[i-k-1]);
            }
            if(ss.insert(arr[i]).second==false){
                return true; // value already present
            }
        }
        return false;
    }
};