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