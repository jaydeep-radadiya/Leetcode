class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int temp = 0;
        for(int ele : nums){
            temp = temp^ele;
        }
        return temp;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> ump;
        // insert into the map
        for(auto it : nums){
            ump[it]++;
        }
        // find the answer
        for(auto it : ump){
            if(it.second!=2){
                return it.first;
            }
        }
        return -1;
    }
};

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_set<int> ss;
        int sum = 0;
        for(int i=0;i<nums.size();i++){
            sum += nums[i];
            ss.insert(nums[i]);
        }
        return 2*accumulate(ss.begin(),ss.end(),0)-sum;
    }
};