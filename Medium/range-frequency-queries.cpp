// time limit exceeded : brute force
class RangeFreqQuery {
private:
    vector<int> nums;
    
public:
    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
    }
    
    // tc : O(right-left)
    int query(int left, int right, int value) {
        int cnt = 0;
        for(int i=left;i<=right;i++){
            if(nums[i]==value){
                cnt++;
            }
        }
        return cnt;
    }
};

// accepted using binary search
// sc : O(n) we store all elements
class RangeFreqQuery {
private:
    unordered_map<int,vector<int>> ump;
    
public:
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            ump[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        // vector<int> vec = ump[value]; // bcoz this tle, it is copying elements
        vector<int> &vec = ump[value];
        int first = lower_bound(vec.begin(),vec.end(),left)-vec.begin();
        int last = upper_bound(vec.begin(),vec.end(),right)-vec.begin();
        return last-first;
    }
};