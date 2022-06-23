class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        if(n==1) return true;
        return n%3==0 && isPowerOfThree(n/3);
    }
};

class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        long long val = 1;
        
        while(val<n){
            val = val*3;
        }
        return val==n;
    }
};