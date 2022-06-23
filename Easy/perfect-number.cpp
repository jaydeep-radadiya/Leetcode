// brute force : O(n)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        
        for(int i=1;i<num;i++){
            if(num%i==0){
                sum += i;
            }
            // little bit optimization
            // if(sum>num){
            //     return false;
            // }
        }
        return sum==num;
    }
};

// tc : O(sqrt(n))
class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        
        for(int i=1;i<=sqrt(num);i++){
            if(num%i==0){
                if(i*i==num)
                    sum += i;
                else
                    sum += (i+num/i);
            }
        }
        sum -= num;
        
        if(sum==num)
            return true;
        else
            return false;
    }
};

// tc : O(logn)
class Solution {
public:
    bool checkPerfectNumber(int num) {
        vector<int> arr = {6, 28, 496, 8128, 33550336};
        return binary_search(arr.begin(),arr.end(),num);
    }
};