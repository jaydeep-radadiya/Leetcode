class Solution {
public:
    int digit(int val){
        return floor(log10(val)+1);
    }
    
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int temp = digit(nums[i]);
            if(temp%2==0) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int digit(int val){
        int nod = 0; // number of digit
        while(val>0){
            val = val/10;
            nod++;
        }
        return nod;
    }
    
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int temp = digit(nums[i]);
            if(temp%2==0) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            string temp = to_string(nums[i]);
            if(temp.size()%2==0) cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int digit(int val){
        if(val/10==0){ // base condition
            return 1;
        }
        return 1+digit(val/10);
    }
    
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(int i=0;i<nums.size();i++){
            int temp = digit(nums[i]);
            if(temp%2==0) cnt++;
        }
        return cnt;
    }
};