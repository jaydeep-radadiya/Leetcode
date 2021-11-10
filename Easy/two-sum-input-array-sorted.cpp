class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(numbers[i]+numbers[j]==target){
                    return {i+1,j+1};
                }
            }
        }
        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int sum = numbers[left]+numbers[right];
            if(sum==target)
                return {left+1,right+1}; // ans should be as per 1 base indexed
            else if(sum>target)
                right--;
            else if(sum<target)
                left++;
        }
        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            if(ump.find(target-numbers[i])!=ump.end()){
                return {ump[target-numbers[i]]+1,i+1};
            }
            ump[numbers[i]] = i;
        }
        return {-1,-1};
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        
        for(int i=0;i<n;i++){
            int temp = target-numbers[i];
            int left = i+1;
            int right = n-1;
            
            while(left<=right){
                int mid = left+(right-left)/2;
                
                if(numbers[mid]==temp)
                    return {i+1,mid+1};
                else if(numbers[mid]>temp)
                    right = mid-1;
                else
                    left = mid+1;
            }
        }
        return {-1,-1};
    }
};