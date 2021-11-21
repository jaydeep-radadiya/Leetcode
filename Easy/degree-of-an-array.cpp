// first method
class ElementInfo {
public:
    int cnt = 0;
    int leftIdx = -1;
    int rightIdx = -1;
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,ElementInfo> elements;
        int mx_degree = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(elements[nums[i]].cnt==0){
                elements[nums[i]].cnt = 1;
                elements[nums[i]].leftIdx = i;
                elements[nums[i]].rightIdx = i;
            }
            else{
                elements[nums[i]].cnt++;
                elements[nums[i]].rightIdx = i;
            }
            mx_degree = max(mx_degree,elements[nums[i]].cnt);
        }
        
        int min_length = INT_MAX;
        for(auto &temp : elements){
            if(temp.second.cnt==mx_degree){
                min_length = min(min_length,temp.second.rightIdx-temp.second.leftIdx+1);
            }
        }
        return min_length;
    }
};

// second method
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> num_count;
        unordered_map<int,int> first_seen;
        
        int n = nums.size();
        int mx_degree = 0;
        int min_length = INT_MAX;
        for(int i=0;i<n;i++){
            if(first_seen.find(nums[i])==first_seen.end()){
                first_seen[nums[i]] = i;   
            }
            num_count[nums[i]]++;
            if(num_count[nums[i]]>mx_degree){
                mx_degree = num_count[nums[i]];
                min_length = i-first_seen[nums[i]]+1;
            }
            else if(num_count[nums[i]]==mx_degree){
                min_length = min(min_length,i-first_seen[nums[i]]+1);
            }
        }
        return min_length;
    }
};

// third method
class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int,int> left;
        unordered_map<int,int> right;
        unordered_map<int,int> count;
        
        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            if(left.find(val)==left.end()){
                left[val] = i;   
            }
            right[val] = i;
            count[val]++;
        }
        
        int degree = 0;
        for(auto &temp : count){
            degree = max(degree,temp.second);
        }
        
        int min_length = INT_MAX;
        for(auto &temp : count){
            if(temp.second==degree){
                min_length = min(min_length,right[temp.first]-left[temp.first]+1);
            }
        }
        return min_length;
    }
};